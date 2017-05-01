#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>

namespace PhinyxEngine {
	class Collision {
		public:
			Collision(sf::RectangleShape &rect);
			void moveRect(float dirX, float dirY);

			bool detectCollision(Collision &colliderRect, float force);
			sf::Vector2f getPosition();
			sf::Vector2f getHalfSize();
		private:
			sf::RectangleShape &m_rect;
	};
}

#endif