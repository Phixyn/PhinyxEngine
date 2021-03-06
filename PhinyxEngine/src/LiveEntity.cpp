#include "../include/LiveEntity.hpp"

// TODO: address code duplication in constructors (see how Entity class does it)

PhinyxEngine::LiveEntity::LiveEntity(int health, int attackPower) :
	Entity(), m_velocity(0.0f, 0.0f)
{
	// TODO: give entities unique IDs and include this in log statement below
	m_logger.log("DEBUG", "Initializing a live entity.");
	m_health = health;
	m_attackPower = attackPower;
}

PhinyxEngine::LiveEntity::LiveEntity(int health, int attackPower, float speed, float jumpHeight) :
	Entity(), m_velocity(0.0f, 0.0f)
{
	m_health = health;
	m_attackPower = attackPower;
	m_speed = speed;
	m_jumpHeight = jumpHeight;
}

void PhinyxEngine::LiveEntity::handleEvents()
{
	// TODO
}

void PhinyxEngine::LiveEntity::update(float deltaTime)
{
	// TODO
}

void PhinyxEngine::LiveEntity::draw()
{
	// TODO
}

/// <summary>
/// Takes a direction vector.
/// Adjusts the live entity's velocity based on the direction vector.
/// </summary>
///
/// <param name="direction"> A SFML Vector2f containing the direction. </param>
void PhinyxEngine::LiveEntity::onCollision(sf::Vector2f direction)
{
	// TODO: simplify if statements here
	// Handle X axis collision
	if (direction.x > 0.0f)
	{
		// Left-hand side collision
		m_velocity.x = 0.0f;
	}

	else if (direction.x < 0.0f)
	{
		// Right-hand side collision
		m_velocity.x = 0.0f;
	}

	// Handle Y axis collision
	if (direction.y > 0.0f)
	{
		// Top collision
		m_velocity.y = 0.0f;
	}

	else if (direction.y < 0.0f)
	{
		// Bottom collision
		m_velocity.y = 0.0f;
		// Entity is on the ground and may jump again
		m_canJump = true;
	}
}

bool PhinyxEngine::LiveEntity::isAggressive() const
{
	return m_aggressive;
}

bool PhinyxEngine::LiveEntity::isDead() const
{
	return m_dead;
}

void PhinyxEngine::LiveEntity::setDead(bool dead)
{
	m_dead = dead;
}

/*
sf::Vector2f PhinyxEngine::LiveEntity::getDirection()
{
	return m_direction;
}

void PhinyxEngine::LiveEntity::setDirection(sf::Vector2f direction)
{
	m_direction = direction;
}
*/