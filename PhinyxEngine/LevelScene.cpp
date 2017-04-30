#include "include/LevelScene.h"
#include "include/Game.h"
#include <fstream>
#include <iostream>

PhinyxEngine::LevelScene::LevelScene(Game &game, std::string levelFilePath, std::string dataFilePath) : Scene(game) {
	m_levelFilePath = levelFilePath;
	m_dataFilePath = dataFilePath;

	std::cout << "Loaded level scene with level file: " << m_levelFilePath << std::endl;
	std::cout << "Loaded level scene with data file: " << m_dataFilePath << std::endl;

	// parseDataFile();
	parseLevelFile();
}

void PhinyxEngine::LevelScene::parseDataFile() {

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
			std::cout << fileLine << std::endl;
			std::vector<std::string> tiles = PhinyxEngine::Util::stringSplit(fileLine, '|');

			for (int i = 0; i < tiles.size(); i++) {
				// TODO: load sprite textures based on data file here
				if (tiles[i] == "5") {
					// temporary rectangle for sprite
					sf::RectangleShape shape(sf::Vector2f(20, 20));
					shape.setFillColor(sf::Color::Red);
					shape.setPosition(i * 20, 0);
					m_sprites.push_back(shape);
				}
				else if (tiles[i] == "3") {
					// temporary rectangle for sprite
					sf::RectangleShape shape(sf::Vector2f(20, 20));
					shape.setFillColor(sf::Color::Green);
					shape.setPosition(0, i * 20);
					m_sprites.push_back(shape);
				}
				std::cout << tiles[i] << std::endl;
			}

			/*
			for (std::string id : tiles) {
			std::cout << id << std::endl;
			}
			*/
		}
		levelFile.close();
	}
}

void PhinyxEngine::LevelScene::input() {

}

void PhinyxEngine::LevelScene::update(float dt) {
}

void PhinyxEngine::LevelScene::draw() {
	m_game_ptr->m_gameWindow.drawRect(m_sprites);
	// std::cout << "Level scene working" << std::endl;
}