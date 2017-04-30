#ifndef PLAYER_H
#define PLAYER_H

#include "LiveEntity.h"
#include <SFML/Graphics.hpp>

namespace PhinyxEngine {
	class Player : public LiveEntity {
		public:
			Player(int health, int attackPower);
			void setTexture(sf::Texture *texture);

			sf::RectangleShape m_rect;
			float m_rectWidth = 48.0f;
			float m_rectHeight = 52.0f;
		private:
	};
}

#endif
