#ifndef LIVE_ENTITY_H
#define LIVE_ENTITY_H

#include "Entity.h"
#include "Logger.h"

namespace PhinyxEngine {
	class LiveEntity : public Entity {
		public:
			LiveEntity(int health, int attackPower);
			LiveEntity(int health, int attackPower, float speed, float jumpHeight);
			void handleEvents() override;
			void update(float deltaTime) override;
			void draw() override;

			// TODO: animate?
			void onCollision(sf::Vector2f direction);

			bool isAggressive();
			bool isDead();
			void setDead(bool dead);

			// TODO: Direction handling
			sf::Vector2f getDirection();
			void setDirection(sf::Vector2f direction);
		protected:
			int m_health;
			int m_attackPower;
			float m_speed;
			float m_jumpHeight;
			bool m_aggressive;
			bool m_dead;
			bool m_canJump = true;
			sf::Vector2f m_velocity;
			// sf::Vector2f m_direction;
			Logger m_logger;
	};
}

#endif