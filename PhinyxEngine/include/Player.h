#ifndef PLAYER_H
#define PLAYER_H

#include "LiveEntity.h"

namespace PhinyxEngine {
	class Player : public LiveEntity {
		public:
			Player(int health, int attackPower, float speed, float jumpHeight);
			// void handleEvents() override;
			void update(float deltaTime) override;
			void draw() override;
	};
}

#endif
