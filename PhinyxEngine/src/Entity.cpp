#include "../include/Entity.h"

/// <summary>
/// Initilizes the Collision object.
/// </summary>
PhinyxEngine::Entity::Entity() : m_collision(m_rect)
{

}

/// <summary>
/// Calls the setTexture method of this Entity's SFML RectangleShape instance
/// to give it a texture.
/// </summary>
///
/// <param name="texture">
/// A pointer to a SFML Texture object required by SFML's setTexture method.
/// </param>
void PhinyxEngine::Entity::setTexture(sf::Texture *texture)
{
	m_rect.setTexture(texture);
}

PhinyxEngine::Collision PhinyxEngine::Entity::getCollision()
{
	return PhinyxEngine::Collision(m_rect);
}