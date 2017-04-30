#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

namespace PhinyxEngine {
	class Player {
		public:
			Player();
			void setTexture(sf::Texture *texture);
			void input();
			void update(float dt);
			void draw();

			sf::RectangleShape m_rect;
			float m_rectWidth = 48.0f;
			float m_rectHeight = 52.0f;
		private:
			
	};
}

#endif
