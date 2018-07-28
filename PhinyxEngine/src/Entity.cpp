#include "../include/Entity.hpp"
#include "../include/IdleEntityState.hpp"

/// <summary>
/// Initilizes the entity's <see cref="Collision">Collision</see> object.
/// </summary>
PhinyxEngine::Entity::Entity() :
	m_collision(m_rect)
{

}

/// <summary>
/// Initilizes the entity's <see cref="Collision">Collision</see> object.
/// </summary>
PhinyxEngine::Entity::Entity(sf::Vector2f size)	:
	m_collision(m_rect)
{
	m_rectWidth = size.x;
	m_rectHeight = size.y;
	m_logger.log("DEBUG", "Creating a new entity.");
	m_rect = sf::RectangleShape(sf::Vector2f(m_rectWidth, m_rectHeight));
	// m_state = new IdleEntityState();
}

PhinyxEngine::Entity::Entity(sf::Vector2f size, sf::Vector2f position) :
	Entity(size)
{
	m_position = position;
	// TODO Rect no longer needed?
	m_rect.setPosition(m_position);
	m_sprite.setPosition(m_position);
	m_infoPanel.setPanelPosition(m_position - sf::Vector2f(0, ((m_rectHeight / 2.0f) + m_infoPanel.getPanelSize().y)));
}

PhinyxEngine::Entity::Entity(sf::Vector2f size, std::string textureFilePath) :
	Entity(size)
{
	setTexture(textureFilePath);
}

PhinyxEngine::Entity::Entity(sf::Vector2f size, sf::Vector2f position, std::string textureFilePath) :
	Entity(size, position)
{
	setTexture(textureFilePath);
}

/// <summary>
/// Calls the setTexture method of this entity's SFML Sprite instance
/// to give it a texture.
/// </summary>
void PhinyxEngine::Entity::setTexture(sf::Texture texture)
{
	m_logger.log("DEBUG", "Applying texture to entity.");
	m_texture = texture;
	m_texture.setSmooth(true);
	m_sprite.setTexture(texture);
}

void PhinyxEngine::Entity::setTexture(std::string textureFilePath)
{
	if (!m_texture.loadFromFile(textureFilePath))
	{
		m_logger.log("ERROR", "Could not load texture image: " + textureFilePath);
		return;
	}

	m_logger.log("INFO", "Loaded entity texture from image file: " + textureFilePath);
	m_logger.log("DEBUG", "Applying texture to entity.");
	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
}

void PhinyxEngine::Entity::setColor(sf::Color color)
{
	m_rect.setFillColor(color);
}

void PhinyxEngine::Entity::setSpriteColor(sf::Color color)
{
	m_sprite.setColor(color);
}

void PhinyxEngine::Entity::setPosition(sf::Vector2f &position)
{
	m_position = position;
	m_sprite.setPosition(position);
}

void PhinyxEngine::Entity::toggleInfoPanel()
{
	m_displayInfoPanel = !m_displayInfoPanel;
}

float PhinyxEngine::Entity::getRectWidth() const
{
	return m_rectWidth;
}

float PhinyxEngine::Entity::getRectHeight() const
{
	return m_rectHeight;
}

sf::Vector2f PhinyxEngine::Entity::getPosition() const
{
	return m_sprite.getPosition();
}

sf::RectangleShape PhinyxEngine::Entity::getRect() const
{
	return m_rect;
}

sf::Sprite PhinyxEngine::Entity::getSprite() const
{
	return m_sprite;
}

PhinyxEngine::InfoPanel& PhinyxEngine::Entity::getInfoPanel()
{
	return m_infoPanel;
}

bool PhinyxEngine::Entity::isInfoPanelEnabled() const
{
	return m_displayInfoPanel;
}

bool PhinyxEngine::Entity::isSelected() const
{
	return m_isSelected;
}

void PhinyxEngine::Entity::toggleSelected()
{
	m_isSelected = !m_isSelected;
}

PhinyxEngine::BaseEntityState* PhinyxEngine::Entity::getState()
{
	// return m_state;
	return nullptr;
}

void PhinyxEngine::Entity::setState(BaseEntityState* state)
{
	// Don't try to use null pointers
	if (state == nullptr)
	{
		m_logger.log("ERROR", "Entity::setState() received null pointer.");
		return;
	}

	/*
	m_state->exit();
	m_state = state;
	m_state->enter();
	*/
}

PhinyxEngine::Collision PhinyxEngine::Entity::getCollision()
{
	return PhinyxEngine::Collision(m_rect);
}
