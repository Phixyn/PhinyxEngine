#include "../include/EnemyMonster.h"

PhinyxEngine::EnemyMonster::EnemyMonster(int health, int attackPower) : LiveEntity(health, attackPower) {
	m_rect = sf::RectangleShape(sf::Vector2f(m_rectWidth, m_rectHeight));
}

void PhinyxEngine::EnemyMonster::setTexture(sf::Texture *texture) {
	m_rect.setTexture(texture);
}