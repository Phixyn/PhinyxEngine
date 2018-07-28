#include "../include/AgentEntity.hpp"

// TODO: address code duplication in constructors (see how Entity class does it)

PhinyxEngine::AgentEntity::AgentEntity(int health, int attackPower, PlayerEntity & player) :
	LiveEntity(health, attackPower), m_playerPtr(&player)
{
}

PhinyxEngine::AgentEntity::AgentEntity(int health, int attackPower, float speed, float jumpHeight, PlayerEntity& player) :
	LiveEntity(health, attackPower, speed, jumpHeight), m_playerPtr(&player)
{
}

PhinyxEngine::AgentEntity::AgentEntity(int health, sf::Vector2f size, sf::Vector2f position, PlayerEntity& player) :
	LiveEntity(health, size, position), m_playerPtr(&player)
{
	setTexture(ENTITY_TEXTURE);
	// Set rotation origin to be the center point of the sprite
	// TODO this is breaking the position of the info panels for agent entities
	// m_sprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
}

PhinyxEngine::AgentEntity::AgentEntity(int health, int attackPower, sf::Vector2f size, sf::Vector2f position, PlayerEntity& player) :
	LiveEntity(health, attackPower, size, position), m_playerPtr(&player)
{
}

PhinyxEngine::AgentEntity::AgentEntity(int health, float speed, sf::Vector2f size, sf::Vector2f position, PlayerEntity& player) :
	LiveEntity(health, speed, size, position), m_playerPtr(&player)
{
	setTexture(ENTITY_TEXTURE);
	// m_sprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
}

PhinyxEngine::AgentEntity::AgentEntity(int health, int attackPower, float speed, sf::Vector2f size, sf::Vector2f position, PlayerEntity& player) :
	LiveEntity(health, attackPower, speed, size, position), m_playerPtr(&player)
{
}

PhinyxEngine::AgentEntity::AgentEntity(int health, int attackPower, float speed, float jumpHeight, sf::Vector2f size, sf::Vector2f position, PlayerEntity& player) :
	LiveEntity(health, attackPower, speed, jumpHeight, size, position), m_playerPtr(&player)
{
}

void PhinyxEngine::AgentEntity::handleEvents(sf::Event sfEvent)
{
	// TODO
}

void PhinyxEngine::AgentEntity::update(float deltaTime)
{
	m_sprite.move(m_velocity);

	// We must also move the associated InfoPanel
	m_infoPanel.setPanelPosition(m_infoPanel.getPanelPosition() + m_velocity);
	// Update the text in the InfoPanel
	std::ostringstream entityInfoSS;
	entityInfoSS << "\nHealth: " << m_health << "\nPosX: " << getPosition().x << "\nPosY: " << getPosition().y << "\nVelocityX: " << m_velocity.x << "\nVelocityY: " << m_velocity.y;
	m_infoPanel.setTextString(entityInfoSS.str());
}

void PhinyxEngine::AgentEntity::draw()
{
	// TODO
}
