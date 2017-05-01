#ifndef ENTITY_H
#define ENTITY_H

#include "Collision.h"
#include <SFML/Graphics.hpp>

namespace PhinyxEngine {
	class Entity {
		public:
			Entity();
			virtual void handleEvents() = 0;
			virtual void update(float deltaTime) = 0;
			virtual void draw() = 0;

			void setTexture(sf::Texture *texture);
			Collision getCollision();

			float m_rectWidth;
			float m_rectHeight;
			sf::RectangleShape m_rect;
			Collision m_collision; // TODO: make this private?
	};
}

#endif