#include "../include/LiveEntity.hpp"
#include "../include/DeadEntityState.hpp"

// TODO: address code duplication in constructors (see how Entity class does it)

PhinyxEngine::LiveEntity::LiveEntity(int health, int attackPower) :
	Entity(), m_health(health), m_attackPower(attackPower), m_velocity(0.0f, 0.0f)
{
	// TODO: give entities unique IDs and include this in log statement below
	m_logger.log("DEBUG", "Initializing a live entity.");
	setMaxSpeed(0.25f);
}

PhinyxEngine::LiveEntity::LiveEntity(int health, int attackPower, float speed, float jumpHeight) :
	Entity(), m_health(health), m_attackPower(attackPower), m_speed(speed), m_jumpHeight(jumpHeight), m_velocity(0.0f, 0.0f)
{
	m_logger.log("DEBUG", "Initializing a live entity.");
	setMaxSpeed(speed);
}

PhinyxEngine::LiveEntity::LiveEntity(int health, sf::Vector2f size, sf::Vector2f position) :
	Entity(size, position), m_health(health), m_velocity(0.0f, 0.0f)
{
	// TODO: give entities unique IDs and include this in log statement below
	m_logger.log("DEBUG", "Initializing a live entity.");
	// setSpriteColor(sf::Color::Red);
	setMaxSpeed(0.25f);

	// Set up entity info panel
	std::ostringstream entityInfoSS;
	// entityInfoSS << "State: " << getState()->getStateName() << "\nHealth: " << m_health << "\nPosX: " << getPosition().x << "\nPosY: " << getPosition().y << "\nVelocityX: " << m_velocity.x << "\nVelocityY: " << m_velocity.y;
	entityInfoSS << "\nHealth: " << m_health << "\nPosX: " << getPosition().x << "\nPosY: " << getPosition().y << "\nVelocityX: " << m_velocity.x << "\nVelocityY: " << m_velocity.y;
	m_infoPanel.setTextString(entityInfoSS.str());
}

PhinyxEngine::LiveEntity::LiveEntity(int health, int attackPower, sf::Vector2f size, sf::Vector2f position) :
	Entity(size, position), m_health(health), m_attackPower(attackPower), m_velocity(0.0f, 0.0f)
{
	setMaxSpeed(0.25f);
}

PhinyxEngine::LiveEntity::LiveEntity(int health, float speed, sf::Vector2f size, sf::Vector2f position) :
	Entity(size, position), m_health(health), m_speed(speed), m_velocity(0.0f, 0.0f)
{
	m_logger.log("DEBUG", "Initializing a live entity.");
	setMaxSpeed(speed);
}

PhinyxEngine::LiveEntity::LiveEntity(int health, int attackPower, float speed, sf::Vector2f size, sf::Vector2f position) :
	Entity(size, position), m_health(health), m_attackPower(attackPower), m_speed(speed), m_velocity(0.0f, 0.0f)
{
	m_logger.log("DEBUG", "Initializing a live entity.");
	setMaxSpeed(speed);
}

PhinyxEngine::LiveEntity::LiveEntity(int health, int attackPower, float speed, float jumpHeight, sf::Vector2f size, sf::Vector2f position) :
	Entity(size, position), m_health(health), m_attackPower(attackPower), m_speed(speed), m_jumpHeight(jumpHeight), m_velocity(0.0f, 0.0f)
{
	m_logger.log("DEBUG", "Initializing a live entity.");
	setMaxSpeed(speed);
}

void PhinyxEngine::LiveEntity::handleEvents(sf::Event sfEvent)
{
	// TODO
}

void PhinyxEngine::LiveEntity::update(float deltaTime)
{
	// m_state->update(); // TODO
	// m_sprite.move(m_velocity);

	// Check if entity is dead
	if (m_health <= 0 && !m_dead)
	{
		setDead(true);
		// TODO Could be a part of setDead()
		setState(new DeadEntityState());
	}
}

void PhinyxEngine::LiveEntity::draw()
{
	// TODO
}

void PhinyxEngine::LiveEntity::setHealth(int health)
{
	m_health = health;
}

int PhinyxEngine::LiveEntity::getHealth()
{
	return m_health;
}

void PhinyxEngine::LiveEntity::setSpeed(float speed)
{
	m_speed = speed;
}

void PhinyxEngine::LiveEntity::setMaxSpeed(float maxSpeed)
{
	m_maxSpeed = maxSpeed;
}

float PhinyxEngine::LiveEntity::getSpeed()
{
	return m_speed;
}

float PhinyxEngine::LiveEntity::getMaxSpeed()
{
	return m_maxSpeed;
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
	// TODO: give entities unique IDs and include this in log statement below
	m_logger.log("DEBUG", "Setting m_dead.");
	m_dead = dead;
}

sf::Vector2f PhinyxEngine::LiveEntity::getVelocity()
{
	return m_velocity;
}

void PhinyxEngine::LiveEntity::setVelocity(sf::Vector2f velocity)
{
	m_velocity = velocity;
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
