#ifndef COLLISION_H
#define COLLISION_H

#include "Logger.h"
#include <SFML/Graphics.hpp>

namespace PhinyxEngine {
	class Collision {
		public:
			Collision(sf::RectangleShape &rect);
			void moveRect(float dirX, float dirY);

			bool handleCollision(Collision &collider, sf::Vector2f &direction, float force);
			sf::Vector2f getPosition();
			sf::Vector2f getHalfSize();
		private:
			sf::RectangleShape &m_rect;
			Logger m_logger;
	};
}

#endif