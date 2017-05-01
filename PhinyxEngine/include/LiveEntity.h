#ifndef LIVE_ENTITY_H
#define LIVE_ENTITY_H

#include "Entity.h"

namespace PhinyxEngine {
	class LiveEntity : public Entity {
		public:
			LiveEntity(int health, int attackPower);
			LiveEntity(int health, int attackPower, float speed);
			void handleEvents() override;
			void update(float deltaTime) override;
			void draw() override;
			// TODO: animate?

			bool isAggressive();
			bool isDead();
			void setDead(bool dead);
			float getDirection();
			void setDirection(float direction);
		protected:
			int m_health;
			int m_attackPower;
			float m_speed;
			float m_direction = 1.0f;
			sf::Vector2f m_acceleration;
			bool m_aggressive;
			bool m_dead;
	};
}

#endif