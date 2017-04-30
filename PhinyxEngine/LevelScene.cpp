#include "include/LevelScene.h"
#include "include/Game.h"
#include <iostream>

PhinyxEngine::LevelScene::LevelScene(Game &game, std::string levelFile, std::string dataFile) : Scene(game) {
	m_levelFile = levelFile;
	m_dataFile = dataFile;

	std::cout << "Loaded level scene with level file: " << m_levelFile << std::endl;
	std::cout << "Loaded level scene with data file: " << m_dataFile << std::endl;
}

void PhinyxEngine::LevelScene::input() {

}

void PhinyxEngine::LevelScene::update(float dt) {
}

void PhinyxEngine::LevelScene::draw() {
	// std::cout << "Level scene working" << std::endl;
}