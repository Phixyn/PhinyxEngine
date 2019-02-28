#include "../include/Collision.hpp"

PhinyxEngine::Collision::Collision(sf::RectangleShape &rect) : m_rect(rect)
{

}

void PhinyxEngine::Collision::moveRect(float dirX, float dirY)
{
	m_rect.move(dirX, dirY);
}

bool PhinyxEngine::Collision::handleCollision(Collision &collider, sf::Vector2f &direction, float force)
{
	// The half sizes will be used to project another rect between colliderRect
	// and this rect.
	sf::Vector2f colliderPos = collider.getPosition();
	sf::Vector2f colliderHalfSize = collider.getHalfSize();
	sf::Vector2f rectPos = getPosition();
	sf::Vector2f rectHalfSize = getHalfSize();

	// Calculate delta difference for two shapes
	float deltaX = colliderPos.x - rectPos.x;
	float deltaY = colliderPos.y - rectPos.y;

	// Calculate intersection points
	float intersectX = abs(deltaX) - (colliderHalfSize.x + rectHalfSize.x);
	float intersectY = abs(deltaY) - (colliderHalfSize.y + rectHalfSize.y);

	// Check if the two rects intersect
	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		// If the two rects intersect, there is a collision
		// Handle any movement required and return true

		// Clamp force (e.g. gravity or pushing against an object) to be between
		// 0.0 and 1.0. We will never need it to be anything else (for now?)
		force = std::min(std::max(force, 0.0f), 1.0f);

		// Handle moving the collided rects based on their forces against
		// each other
		if (intersectX > intersectY)
		{
			// Physics.exe
			// The collision is based on the X axis because intersectX is bigger
			// So we need to move rects based on the X axis

			// Calculate which direction to move the rects
			if (deltaX > 0.0f)
			{
				// Move the two rects based on their force
				moveRect(intersectX * (1.0f - force), 0.0f);
				// Move the collider in the opposite direction
				collider.moveRect(-intersectX * force, 0.0f);
				// Set the collider's directions
				direction.x = 1.0f;
				direction.y = 0.0f;
			}
			else
			{
				// Opposite direction to the above
				moveRect(-intersectX * (1.0f - force), 0.0f);
				collider.moveRect(intersectX * force, 0.0f);
				direction.x = -1.0f;
				direction.y = 0.0f;
			}
		}
		else
		{
			// Move rects on the Y axis
			if (deltaY > 0.0f)
			{
				moveRect(0.0f, intersectY * (1.0f - force));
				collider.moveRect(0.0f, -intersectY * force);
				direction.x = 0.0f;
				direction.y = 1.0f;
			}
			else
			{
				moveRect(0.0f, -intersectY * (1.0f - force));
				collider.moveRect(0.0f, intersectY * force);
				direction.x = 0.0f;
				direction.y = -1.0f;
			}
		}
		return true;
	}
	return false;
}

sf::Vector2f PhinyxEngine::Collision::getPosition() const
{
	return m_rect.getPosition();
}

sf::Vector2f PhinyxEngine::Collision::getHalfSize() const
{
	return m_rect.getSize() / 2.0f;
}