#include "../include/Entity.h"

PhinyxEngine::Entity::Entity() {

}

void PhinyxEngine::Entity::setTexture(sf::Texture *texture) {
	m_rect.setTexture(texture);
}