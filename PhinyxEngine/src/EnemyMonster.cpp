#include "../include/EnemyMonster.hpp"

PhinyxEngine::EnemyMonster::EnemyMonster(int health, int attackPower) :
	LiveEntity(health, attackPower)
{
	m_rectWidth = 48.0f;
	m_rectHeight = 52.0f;
	m_rect = sf::RectangleShape(sf::Vector2f(m_rectWidth, m_rectHeight));
}