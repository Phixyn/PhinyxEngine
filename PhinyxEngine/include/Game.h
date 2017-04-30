#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Scene.h"
#include <queue>

namespace PhinyxEngine {
	class Game {
		public:
			Game(bool debug);
			void makeGameWindow(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE);
			void mainLoop();

			void addScene(std::unique_ptr<Scene> scene);
			void removeScene();
			void changeScene(std::unique_ptr<Scene> scene);

			Window m_gameWindow;
		private:
			float m_deltaTime;
			bool m_debugMode;
			std::queue<std::unique_ptr<Scene>> m_scene_queue;
			sf::Clock m_clock;
	};
}

#endif