#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

namespace PhinyxEngine {
	class Window {
		public:
			void init(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE);
			void clear();
			void render();
			void drawRect(sf::RectangleShape rect);
			void drawText(sf::Text text);
			void pollForEvents();
			bool isOpen();
			unsigned int getWidth();
			unsigned int getHeight();
			std::string getTitle();
		private:
			std::unique_ptr<sf::RenderWindow> window;
			unsigned int m_WIDTH;
			unsigned int m_HEIGHT;
			std::string m_TITLE;
	};
}

#endif
