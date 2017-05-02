#include "../include/Entity.h"

/// <summary> Initilizes the Collision. </summary>
PhinyxEngine::Entity::Entity() : m_collision(m_rect) {

}

void PhinyxEngine::Entity::setTexture(sf::Texture *texture) {
	m_rect.setTexture(texture);
}

PhinyxEngine::Collision PhinyxEngine::Entity::getCollision() {
	return PhinyxEngine::Collision(m_rect);
}