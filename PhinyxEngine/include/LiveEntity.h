#ifndef LIVE_ENTITY_H
#define LIVE_ENTITY_H

#include "Entity.h"

namespace PhinyxEngine {
	class LiveEntity : public Entity {
		public:
			LiveEntity(int health, int attackPower);
			void input() override;
			void update(float deltaTime) override;
			void draw() override;
			// TODO: animate?

			bool isAggressive();
			bool isDead();
		private:
			int m_health;
			int m_attackPower;
			bool m_aggressive;
			bool m_dead;
	};
}

#endif