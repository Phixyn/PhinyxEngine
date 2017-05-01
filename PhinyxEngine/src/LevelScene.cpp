#include "../include/LevelScene.h"
#include "../include/Game.h"
#include "../include/EnemyMonster.h"
#include <fstream>

PhinyxEngine::LevelScene::LevelScene(Game &game, std::string levelFilePath, std::string dataFilePath) :
		Scene(game), m_player(100, 20, 150.0f, 54.0f)
{
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
		m_logger.log("ERROR", "Unable to open level data file.");
	}

	else {
		while (std::getline(dataFile, fileLine)) {
			if (fileLine.find('=') != std::string::npos) {
				std::vector<std::string> lineSplitVector = PhinyxEngine::Util::stringSplit(fileLine, '=');
				std::string textureID = lineSplitVector[0];
				std::string textureFileName = lineSplitVector[1];
				sf::Texture textureToLoad;
				textureToLoad.loadFromFile(textureFileName);
				m_logger.log("INFO", "Loaded texture file: " + textureFileName);
				// Add texture ID (e.g. '1') and texture file name (e.g. 'grass.png') to map
				m_levelTextures.insert(std::make_pair(textureID, textureToLoad));
			}
		}
		m_logger.log("INFO", "Loaded level data file: " + m_dataFilePath);
	}
}

void PhinyxEngine::LevelScene::parseLevelFile() {
	std::ifstream levelFile;
	levelFile.open(m_levelFilePath);

	if (!levelFile.is_open()) {
		m_logger.log("ERROR", "Unable to open level file.");
	}

	else {
		std::string fileLine;
		std::vector<std::string> fileLines;

		// Read all file lines and store in fileLines vector
		// TODO: Ignore lines that begin with a #
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
			for (int column = 0; column < tiles.size(); column++) {
				if (tiles[column] == "-") {
					// Blank tiles
					continue;
				}

				else if (tiles[column] == "0") {
					// Player sprite
					m_player.setTexture(&m_levelTextures[tiles[column]]);
					m_logger.log("DEBUG", "Player rect width: " + std::to_string(m_player.m_rectWidth));
					m_logger.log("DEBUG", "Player rect height: " + std::to_string(m_player.m_rectHeight));
					m_logger.log("DEBUG", "Player x: " + std::to_string((column * m_player.m_rectWidth)));
					m_logger.log("DEBUG", "Player y: " + std::to_string((row * m_player.m_rectHeight)));
					m_player.m_rect.setPosition(column * m_textureSize, row * m_textureSize);
					// m_liveEntities.push_back(&m_player);
				}

				else if (tiles[column] == "4") {
					// Enemy sprite
					// TODO: This is temporary and should be improved
					// Ideally we should check tiles[column] == "enemy_x"
					EnemyMonster enemy(100, 20);
					enemy.setTexture(&m_levelTextures[tiles[column]]);
					enemy.m_rect.setPosition(column * m_textureSize, row * m_textureSize);
					// m_liveEntities.push_back(&enemy);
				}

				else {
					// Create a shape and set its texture based on the data line
					sf::RectangleShape shape(sf::Vector2f(m_textureSize, m_textureSize));
					shape.setTexture(&m_levelTextures[tiles[column]]);
					shape.setPosition(column * m_textureSize, row * m_textureSize);
					// Append a new entity with rect to tileEntities vector
					m_tileEntities.push_back(PhinyxEngine::TileEntity(shape));
				}
			}

			// TODO: can't read window height atm for some reason
			// row -= m_textureSize;
			row -= 1;
		}
		levelFile.close();
		m_logger.log("INFO", "Loaded level file: " + m_levelFilePath);
	}
}

void PhinyxEngine::LevelScene::handleEvents() {
	m_player.handleEvents();
	// TODO: enemies
}

void PhinyxEngine::LevelScene::update(float deltaTime) {
	m_player.update(deltaTime);

	// The direction vector to be used by onCollision
	// The vector is set by handleCollision and used in onCollision to set the
	// entity's velocity according to the direction given by handleCollision
	sf::Vector2f direction;
	for (TileEntity &tile : m_tileEntities) {
		// Passing 1.0f as force needed to push the tile. Which means our
		// player can't walk through the wall as they won't have enough force
		// and the tile will always push the player away
		if (tile.getCollision().handleCollision(m_player.getCollision(), direction, 1.0f)) {
			m_player.onCollision(direction);
		}
	}
	// TODO: enemies
}

void PhinyxEngine::LevelScene::draw() {
	m_game_ptr->m_gameWindow.drawRect(m_player.m_rect);

	// TODO: liveEntities
	// m_game_ptr->m_gameWindow.drawRect(m_enemy.m_rect);
	/*
	for (LiveEntity* liveEntity : m_liveEntities) {
	m_game_ptr->m_gameWindow.drawRect(liveEntity->m_rect);
	}
	*/

	// Draw our tiles
	for (TileEntity &tile : m_tileEntities) {
		m_game_ptr->m_gameWindow.drawRect(tile.m_rect);
	}
}