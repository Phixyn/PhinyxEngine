#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Scene.h"
#include <queue>

namespace PhinyxEngine {
	class Game {
		public:
			Game(bool debug);
			/// <summary> Makes the game window. </summary>
			void makeGameWindow(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE);
			/// <summary> Handles the game's main loop. </summary>
			void mainLoop();

			/// <summary> Adds a new scene to the game. </summary>
			void addScene(std::unique_ptr<Scene> scene);
			/// <summary> Removes a scene from the game. </summary>
			void removeScene();
			/// <summary> Changes the game scene. </summary>
			void changeScene(std::unique_ptr<Scene> scene);

			Window m_gameWindow;
		private:
			float m_deltaTime;
			bool m_debugMode;
			std::queue<std::unique_ptr<Scene>> m_scene_queue;
			sf::Clock m_clock;
			Logger m_logger;
	};
}

#endif