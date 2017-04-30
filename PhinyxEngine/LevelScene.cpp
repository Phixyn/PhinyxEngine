#include "include/LevelScene.h"
#include "include/Game.h"
#include <fstream>
#include <iostream>

PhinyxEngine::LevelScene::LevelScene(Game &game, std::string levelFilePath, std::string dataFilePath) : Scene(game) {
	m_levelFilePath = levelFilePath;
	m_dataFilePath = dataFilePath;

	std::cout << "Loaded level scene with level file: " << m_levelFilePath << std::endl;
	std::cout << "Loaded level scene with data file: " << m_dataFilePath << std::endl;

	parseDataFile();
	parseLevelFile();
}

void PhinyxEngine::LevelScene::parseDataFile() {
	std::string fileLine;
	std::ifstream dataFile;
	dataFile.open(m_dataFilePath);

	if (!dataFile.is_open()) {
		printf("[ERROR] Unable to open level data file\n");
	}

	else {
		while (std::getline(dataFile, fileLine)) {
			if (fileLine.find('=') != std::string::npos) {
				std::cout << fileLine << std::endl;
				std::string textureID = PhinyxEngine::Util::stringSplit(fileLine, '=')[0];
				std::string textureFileName = PhinyxEngine::Util::stringSplit(fileLine, '=')[1];
				std::cout << textureFileName << std::endl;
				sf::Texture textureToLoad;
				textureToLoad.loadFromFile(textureFileName);
				m_levelTextures.insert(std::make_pair(textureID, textureToLoad));
			}
		}
	}
}

void PhinyxEngine::LevelScene::parseLevelFile() {
	std::string fileLine;
	std::ifstream levelFile;
	levelFile.open(m_levelFilePath);

	if (!levelFile.is_open()) {
		printf("[ERROR] Unable to open level file\n");

	}

	else {
		while (std::getline(levelFile, fileLine)) {
			// std::cout << fileLine << std::endl;
			std::vector<std::string> tiles = PhinyxEngine::Util::stringSplit(fileLine, '|');

			for (int i = 0; i < tiles.size(); i++) {
				// TODO: load sprite textures based on data file here
				if (tiles[i] == "5") {
					// temporary rectangle for sprite
					sf::RectangleShape shape(sf::Vector2f(64, 64));
					shape.setFillColor(sf::Color::Cyan);
					shape.setPosition(i * 64, 0);
					m_sprites.push_back(shape);
				}

				else if (tiles[i] == "4") {
					// temporary rectangle for sprite
					sf::RectangleShape shape(sf::Vector2f(64, 64));
					shape.setFillColor(sf::Color::White);
					shape.setPosition(0, i * 64);
					m_sprites.push_back(shape);
				}

				else if (tiles[i] == "0") {
					continue;
				}

				else {
					sf::RectangleShape shape(sf::Vector2f(64, 64));
					std::cout << tiles[i] << std::endl;
					shape.setTexture(&m_levelTextures[tiles[i]]);
					shape.setPosition(i * 64, 416);
					m_sprites.push_back(shape);
				}
				// std::cout << tiles[i] << std::endl;
			}
		}
		levelFile.close();
	}
}

void PhinyxEngine::LevelScene::input() {

}

void PhinyxEngine::LevelScene::update(float dt) {
}

void PhinyxEngine::LevelScene::draw() {
	m_game_ptr->m_gameWindow.drawRectVector(m_sprites);
}