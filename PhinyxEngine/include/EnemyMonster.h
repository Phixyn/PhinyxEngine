#ifndef ENEMY_MONSTER_H
#define ENEMY_MONSTER_H

#include "LiveEntity.h"

namespace PhinyxEngine {
	class EnemyMonster : public LiveEntity {
		public:
			EnemyMonster(int health, int attackPower);
	};
}

#endif