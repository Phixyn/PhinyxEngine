#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

namespace PhinyxEngine {
	class Window {
		public:
			void init();
			void clear();
			void render();
			void pollForEvents();
			bool isOpen();
		private:
			std::unique_ptr<sf::RenderWindow> window;
			const unsigned int WIDTH = 600;
			const unsigned int HEIGHT = 480;
			const std::string TITLE = "Phinyx Engine";
	};
}

#endif
