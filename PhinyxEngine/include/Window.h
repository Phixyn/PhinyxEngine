#ifndef WINDOW_H
#define WINDOW_H

#include "Logger.h"
#include <string>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

namespace PhinyxEngine {
	class Window {
		public:
			void init(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, bool showDebugPane);
			void clear();
			void render();
			void drawRect(sf::RectangleShape rect);
			void drawRectVector(std::vector<sf::RectangleShape> rectVector);
			void drawText(sf::Text text);
			void handleEvents();

			bool isOpen();
			unsigned int getWidth();
			unsigned int getHeight();
			std::string getTitle();
		private:
			bool m_showDebugPane;
			unsigned int m_WIDTH;
			unsigned int m_HEIGHT;
			std::string m_TITLE;
			std::unique_ptr<sf::RenderWindow> m_window;

			sf::RectangleShape m_debugPane;
			sf::Text m_debugTextDeltaTimer;
			sf::Font m_debugPaneFont;

			Logger logger;
	};
}

#endif
