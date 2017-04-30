#include "include/LevelScene.h"
#include <iostream>
#include "include/Game.h"
#include <string>

PhinyxEngine::LevelScene::LevelScene(Game &game) : Scene(game) {
}

void PhinyxEngine::LevelScene::input() {

}

void PhinyxEngine::LevelScene::update(float dt) {
}

void PhinyxEngine::LevelScene::draw() {
	std::cout << "Level scene working" << std::endl;
}