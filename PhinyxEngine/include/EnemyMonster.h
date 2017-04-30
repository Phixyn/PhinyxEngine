#ifndef ENEMY_MONSTER_H
#define ENEMY_MONSTER_H

#include "LiveEntity.h"
#include <SFML/Graphics.hpp>

namespace PhinyxEngine {
	class EnemyMonster : public LiveEntity {
		public:
			EnemyMonster(int health, int attackPower);
			void setTexture(sf::Texture *texture);

			sf::RectangleShape m_rect;
			float m_rectWidth = 48.0f;
			float m_rectHeight = 52.0f;
	};
}

#endif