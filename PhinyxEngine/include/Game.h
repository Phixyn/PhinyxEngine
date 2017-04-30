#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "LevelScene.h"
#include <memory>
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

			Window gameWindow;
			bool debugMode;
		private:
			std::queue<std::unique_ptr<Scene>> m_scene_queue;
			sf::Clock clock;
			float deltaTime;
	};
}

#endif