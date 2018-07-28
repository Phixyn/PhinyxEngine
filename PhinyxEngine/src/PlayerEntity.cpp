#include "../include/PlayerEntity.hpp"

// TODO: address code duplication in constructors (see how Entity class does it)

PhinyxEngine::PlayerEntity::PlayerEntity(int health, int attackPower, float speed, float jumpHeight) :
	LiveEntity(health, attackPower, speed, jumpHeight)
{
	// setTexture(ENTITY_TEXTURE); this is from our SFML Game AI demos, not sure we need it in these constructors
	m_rectWidth = 48.0f;
	m_rectHeight = 52.0f;
	m_rect = sf::RectangleShape(sf::Vector2f(m_rectWidth, m_rectHeight));
	// Set the origin (center point for all transformations) of the
	// player's rectangle to its center
	// m_rect.setOrigin(sf::Vector2f(m_rect.getSize().x / 2.0f, m_rect.getSize().y));
}

PhinyxEngine::PlayerEntity::PlayerEntity(int health, sf::Vector2f size, sf::Vector2f position) :
	LiveEntity(health, size, position)
{
	// setTexture(ENTITY_TEXTURE);
	// Code from our SFML Game AI demos, not sure if needed in this project
	// Set rotation origin to be the center point of the sprite
	// m_sprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
	// Set rotation so player is pointing upwards
	// m_sprite.setRotation(-90.0f);
}

PhinyxEngine::PlayerEntity::PlayerEntity(int health, int attackPower, sf::Vector2f size, sf::Vector2f position) :
	LiveEntity(health, attackPower, size, position)
{
	// setTexture(ENTITY_TEXTURE);
	// m_sprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
	// m_sprite.setRotation(-90.0f);
}

PhinyxEngine::PlayerEntity::PlayerEntity(int health, float speed, sf::Vector2f size, sf::Vector2f position) :
	LiveEntity(health, speed, size, position)
{
	// setTexture(ENTITY_TEXTURE);
	// m_sprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
	// m_sprite.setRotation(-90.0f);
}

PhinyxEngine::PlayerEntity::PlayerEntity(int health, int attackPower, float speed, sf::Vector2f size, sf::Vector2f position) :
	LiveEntity(health, attackPower, speed, size, position)
{
	// setTexture(ENTITY_TEXTURE);
	// m_sprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
	// m_sprite.setRotation(-90.0f);
}


PhinyxEngine::PlayerEntity::PlayerEntity(int health, int attackPower, float speed, float jumpHeight, sf::Vector2f size, sf::Vector2f position) :
	LiveEntity(health, attackPower, speed, jumpHeight, size, position)
{
	// setTexture(ENTITY_TEXTURE);
	// m_sprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
	// m_sprite.setRotation(-90.0f);
}

void PhinyxEngine::PlayerEntity::handleEvents(sf::Event sfEvent)
{
	/* TODO refactor this to match SFML Game AI demos project?
	Needs testing.
	Code from SFML Game AI demos handleEvents (entire method):

	if (sfEvent.type == sf::Event::KeyPressed)
	{
		float angle = m_sprite.getRotation();
		switch (sfEvent.key.code)
		{
			case sf::Keyboard::W:
				setVelocity(sf::Vector2f((float)(cos(angle * M_PI / 180.0f)), (float)(sin(angle * M_PI / 180.0f))));
				break;
			case sf::Keyboard::A:
				m_sprite.rotate(-5.0f);
				setVelocity(sf::Vector2f((float)(cos(angle * M_PI / 180.0f)), (float)(sin(angle * M_PI / 180.0f))));
				break;
			case sf::Keyboard::S:
				setVelocity(sf::Vector2f(0.0f, 0.0f));
				break;
			case sf::Keyboard::D:
				m_sprite.rotate(5.0f);
				setVelocity(sf::Vector2f((float)(cos(angle * M_PI / 180.0f)), (float)(sin(angle * M_PI / 180.0f))));
				break;
			default:
				break;
		}
	}
	*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		m_velocity.x -= m_speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		m_velocity.x += m_speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && m_canJump)
	{
		m_canJump = false;
		// For the jumping velocity calculation, a kinematic equation is used
		// which is explained here: https://youtu.be/v1V3T5BPd7E (1:50).
		// TODO: 400.0f = gravity, should be moved to a variable
		m_velocity.y = -sqrtf(2.0f * 400.0f * m_jumpHeight);
	}
}

/// <summary>
/// Updates the player's velocity based on movement keys pressed. Moves the
/// player's rectangle based on their velocity.
/// </summary>
void PhinyxEngine::PlayerEntity::update(float deltaTime)
{
	// m_state->update(); // TODO
	// Gradually decrease velocity if a movement key is not pressed
	// m_velocity.x *= 0.5f;
	// Set velocity to 0 if a movement key is not pressed
	m_velocity.x = 0.0f;

	// TODO: Improve this to take a mapping of keybinds set in the game
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		m_velocity.x -= m_speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		m_velocity.x += m_speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && m_canJump)
	{
		m_canJump = false;
		// For the jumping velocity calculation, a kinematic equation is used
		// which is explained here: https://youtu.be/v1V3T5BPd7E (1:50).
		// TODO: 400.0f = gravity, should be moved to a variable
		m_velocity.y = -sqrtf(2.0f * 400.0f * m_jumpHeight);
	}*/

	// Handle gravity so that the player gradually falls if they are in the air
	m_velocity.y += 400.0f * deltaTime;

	m_rect.move(m_velocity * deltaTime);

	// We must also move the associated InfoPanel
	m_infoPanel.setPanelPosition(m_infoPanel.getPanelPosition() + m_velocity);
	// Update the text in the InfoPanel
	std::ostringstream entityInfoSS;
	// entityInfoSS << "State: " << getState()->getStateName() << "\nHealth: " << m_health << "\nPosX: " << getPosition().x << "\nPosY: " << getPosition().y << "\nVelocityX: " << m_velocity.x << "\nVelocityY: " << m_velocity.y;
	entityInfoSS << "\nHealth: " << m_health << "\nPosX: " << getPosition().x << "\nPosY: " << getPosition().y << "\nVelocityX: " << m_velocity.x << "\nVelocityY: " << m_velocity.y;
	m_infoPanel.setTextString(entityInfoSS.str());
}

void PhinyxEngine::PlayerEntity::draw()
{
	// TODO
}
