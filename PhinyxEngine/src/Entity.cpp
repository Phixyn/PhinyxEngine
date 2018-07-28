#include "../include/Entity.hpp"

/// <summary>
/// Initilizes the entity's <see cref="Collision">Collision</see> object.
/// </summary>
PhinyxEngine::Entity::Entity() :
	m_collision(m_rect)
{

}

/// <summary>
/// Calls the setTexture method of this Entity's SFML RectangleShape instance
/// to give it a texture.
/// </summary>
void PhinyxEngine::Entity::setTexture(sf::Texture *texture)
{
	m_rect.setTexture(texture);
}

PhinyxEngine::Collision PhinyxEngine::Entity::getCollision()
{
	return PhinyxEngine::Collision(m_rect);
}