#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

namespace PhinyxEngine {
	class Entity {
		public:
			Entity();
			virtual void input() = 0;
			virtual void update(float deltaTime) = 0;
			virtual void draw() = 0;

			void setTexture(sf::Texture *texture);

			float m_rectWidth;
			float m_rectHeight;
			sf::RectangleShape m_rect;
	};
}

#endif