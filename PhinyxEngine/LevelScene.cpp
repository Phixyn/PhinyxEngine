#include "include/LevelScene.h"
#include <iostream>
#include "include/Game.h"
#include <string>

PhinyxEngine::LevelScene::LevelScene(Game &game) : Scene(game) {
	debugPane = sf::RectangleShape(sf::Vector2f(250.0f, 150.0f));
	debugPane.setFillColor(sf::Color::White);
}

void PhinyxEngine::LevelScene::input() {

}

void PhinyxEngine::LevelScene::update(float dt) {
	if (m_game_ptr->debugMode == true) {
		debugPaneFont.loadFromFile("arial.ttf");

		debugTextDeltaTimer.setFont(debugPaneFont);
		debugTextDeltaTimer.setFillColor(sf::Color::Black);
		debugTextDeltaTimer.setCharacterSize(12);
		debugTextDeltaTimer.setString("Delta timer: " + std::to_string(dt));
		m_game_ptr->gameWindow.drawRect(debugPane);
		m_game_ptr->gameWindow.drawText(debugTextDeltaTimer);
	}
}

void PhinyxEngine::LevelScene::draw() {
	//std::cout << "Level scene working" << std::endl;
}