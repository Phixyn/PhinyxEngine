#include "../include/TileEntity.hpp"

/// <summary>
/// Calls the superclass constructor and initializes member variables.
/// </summary>
PhinyxEngine::TileEntity::TileEntity(sf::RectangleShape rect) :
	Entity()
{
	m_rect = rect;
}

void PhinyxEngine::TileEntity::handleEvents()
{
	// TODO
}

void PhinyxEngine::TileEntity::update(float deltaTime)
{
	// TODO
}

void PhinyxEngine::TileEntity::draw()
{
	// TODO
}