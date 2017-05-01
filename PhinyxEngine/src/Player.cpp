#include "../include/Player.h"

PhinyxEngine::Player::Player(int health, int attackPower, float speed, float jumpHeight) :
	LiveEntity(health, attackPower, speed, jumpHeight)
{
	m_rectWidth = 48.0f;
	m_rectHeight = 52.0f;
	m_rect = sf::RectangleShape(sf::Vector2f(m_rectWidth, m_rectHeight));
}

/*
void PhinyxEngine::Player::handleEvents() {

}
*/

void PhinyxEngine::Player::update(float deltaTime) {
	// Gradually decrease velocity if a movement key is not pressed
	// m_velocity.x *= 0.5f;
	m_velocity.x = 0.0f;

	// TODO: Improve this to take a mapping of keybinds set in the game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		m_velocity.x -= m_speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		m_velocity.x += m_speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && m_canJump) {
		m_canJump = false;
		// Maths.exe is not responding
		// Close program | Google solution
		// 400.0f = gravity, should be moved to a variable
		m_velocity.y = -sqrtf(2.0f * 400.0f * m_jumpHeight);
	}

	// Handle gravity so that the player gradually falls if they are in the air
	m_velocity.y += 400.0f * deltaTime;

	m_rect.move(m_velocity * deltaTime);
}

void PhinyxEngine::Player::draw() {
	// TODO
}