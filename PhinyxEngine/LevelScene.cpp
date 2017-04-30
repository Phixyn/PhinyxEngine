#include "include/LevelScene.h"
#include "include/Game.h"
#include <fstream>
#include <iostream>

PhinyxEngine::LevelScene::LevelScene(Game &game, std::string levelFilePath, std::string dataFilePath) : Scene(game) {
	m_levelFilePath = levelFilePath;
	m_dataFilePath = dataFilePath;
	parseDataFile();
	parseLevelFile();
}

void PhinyxEngine::LevelScene::parseDataFile() {
	std::string fileLine;
	std::ifstream dataFile;
	dataFile.open(m_dataFilePath);

	if (!dataFile.is_open()) {
		std::cout << "[ERROR] Unable to open level data file\n" << std::endl;
	}

	else {
		while (std::getline(dataFile, fileLine)) {
			if (fileLine.find('=') != std::string::npos) {
				std::vector<std::string> lineSplitVector = PhinyxEngine::Util::stringSplit(fileLine, '=');
				std::string textureID = lineSplitVector[0];
				std::string textureFileName = lineSplitVector[1];
				sf::Texture textureToLoad;
				textureToLoad.loadFromFile(textureFileName);
				// Add texture ID (e.g. '1') and texture file name (e.g. 'grass.png') to map
				m_levelTextures.insert(std::make_pair(textureID, textureToLoad));
			}
		}
		std::cout << "[INFO] Loaded level data file: " << m_dataFilePath << std::endl;
	}
}

void PhinyxEngine::LevelScene::parseLevelFile() {
	std::ifstream levelFile;
	levelFile.open(m_levelFilePath);

	if (!levelFile.is_open()) {
		std::cout << "[ERROR] Unable to open level file.\n" << std::endl;
	}

	else {
		std::string fileLine;
		std::vector<std::string> fileLines;

		// Read all file lines and store in fileLines vector
		while (std::getline(levelFile, fileLine)) {
			fileLines.push_back(fileLine);
		}

		// We will start setting the position for the sprites
		// from the bottom to the top of the screen
		// TODO: Should be replaces with window height but it's not working atm
		// unsigned int row = m_game_ptr->m_gameWindow.getHeight();
		unsigned int row = fileLines.size() - 1;
		// Read file lines from end to beginning
		// Iterate through lines
		for (auto iterator = fileLines.rbegin(); iterator != fileLines.rend(); ++iterator) {
			std::vector<std::string> tiles = PhinyxEngine::Util::stringSplit(*iterator, '|');

			// Iterate through tiles in this line
			for (int i = 0; i < tiles.size(); i++) {
				if (tiles[i] == "5") {
					// TODO: temporary rectangle for sky
					sf::RectangleShape shape(sf::Vector2f(48, 48));
					shape.setFillColor(sf::Color::Cyan);
					shape.setPosition(i * 48, row * 48);
					m_sprites.push_back(shape);
				}

				else if (tiles[i] == "0") {
					// TODO: 0 was meant to be for player
					continue;
				}

				// Create a shape and set its texture based on the data line
				else {
					sf::RectangleShape shape(sf::Vector2f(48, 48));
					shape.setTexture(&m_levelTextures[tiles[i]]);
					shape.setPosition(i * 48, row * 48);
					// Append shape with texture to scene sprites
					m_sprites.push_back(shape);
				}
			}

			// TODO: can't read window height atm for some reason
			// row -= 48;
			row -= 1;
		}
		levelFile.close();
		std::cout << "[INFO] Loaded level file: " << m_levelFilePath << std::endl;
	}
}

void PhinyxEngine::LevelScene::input() {
	// TODO
}

void PhinyxEngine::LevelScene::update(float dt) {
	// TODO
}

void PhinyxEngine::LevelScene::draw() {
	m_game_ptr->m_gameWindow.drawRectVector(m_sprites);
}