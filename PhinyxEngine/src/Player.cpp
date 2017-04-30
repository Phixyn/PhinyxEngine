#include "../include/Player.h"

PhinyxEngine::Player::Player() {
	m_rect = sf::RectangleShape(sf::Vector2f(m_rectWidth, m_rectHeight));
}

void PhinyxEngine::Player::setTexture(sf::Texture *texture) {
	m_rect.setTexture(texture);
}