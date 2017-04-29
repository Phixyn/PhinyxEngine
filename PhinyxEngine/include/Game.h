#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "LevelScene.h"
#include <memory>
#include <queue>

namespace PhinyxEngine {
	class Game {
		public:
			Game();
			void mainLoop();

			void addScene(std::unique_ptr<Scene> scene);
			void removeScene();
			void changeScene(std::unique_ptr<Scene> scene);

			Window gameWindow;
			bool showDebugPane;
		private:
			std::queue<std::unique_ptr<Scene>> m_scene_queue;
	};
}

#endif