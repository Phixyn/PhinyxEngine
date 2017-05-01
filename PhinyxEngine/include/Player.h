#ifndef PLAYER_H
#define PLAYER_H

#include "LiveEntity.h"

namespace PhinyxEngine {
	class Player : public LiveEntity {
		public:
			Player(int health, int attackPower);
	};
}

#endif
