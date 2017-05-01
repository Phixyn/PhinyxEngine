#include "../include/Player.h"

PhinyxEngine::Player::Player(int health, int attackPower) : LiveEntity(health, attackPower) {
	m_rectWidth = 48.0f;
	m_rectHeight = 52.0f;
	m_rect = sf::RectangleShape(sf::Vector2f(m_rectWidth, m_rectHeight));
}


void PhinyxEngine::Player::handleEvents() {
	// TODO: Improve this to take a mapping of keybinds set in the game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		m_rect.move(-0.1f, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		m_rect.move(0.1f, 0.0f);
	}

	// TODO: Jump
}

void PhinyxEngine::Player::update(float deltaTime) {
	// TODO
}

void PhinyxEngine::Player::draw() {
	// TODO
}