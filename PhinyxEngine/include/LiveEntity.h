#ifndef LIVE_ENTITY_H
#define LIVE_ENTITY_H

#include "Entity.h"

namespace PhinyxEngine {
	class LiveEntity : public Entity {
		public:
			LiveEntity(int health, int attackPower);
			void input() override;
			void update(float dt) override;
			void draw() override;
			// TODO: animate?

			bool isAggressive();
		private:
			int m_health;
			int m_attackPower;
			bool m_aggressive;
	};
}

#endif