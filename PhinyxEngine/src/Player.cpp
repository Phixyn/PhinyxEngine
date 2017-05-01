#include "../include/Player.h"

PhinyxEngine::Player::Player(int health, int attackPower, float speed) : LiveEntity(health, attackPower, speed) {
	m_rectWidth = 48.0f;
	m_rectHeight = 52.0f;
	m_rect = sf::RectangleShape(sf::Vector2f(m_rectWidth, m_rectHeight));
}

/*
void PhinyxEngine::Player::handleEvents() {

}
*/

void PhinyxEngine::Player::update(float deltaTime) {
	// Reset acceleration to stop movement
	m_acceleration.x = 0.0f;

	// TODO: Improve this to take a mapping of keybinds set in the game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		if (m_direction == 1.0f) {
			m_direction = -abs(m_direction);
		}

		m_acceleration.x -= m_speed * deltaTime;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		if (m_direction == -1.0f) {
			m_direction = -abs(m_direction);
		}

		m_acceleration.x += m_speed * deltaTime;
	}

	m_rect.move(m_acceleration);
	// TODO: Jump
}

void PhinyxEngine::Player::draw() {
	// TODO
}