#ifndef GAME_H
#define GAME_H

#include "Window.h"
#include "Scene.h"
#include <queue>

/// <summary>
/// TODO: Placeholder documentation for namespace PhinyxEngine.
/// </summary>
namespace PhinyxEngine
{
	/// <summary>
	/// TODO: Placeholder documentation for Game class.
	/// </summary>
	class Game
	{
		public:
			/// <summary> Default constructor. </summary>
			Game(bool debug);

			/// <summary>
			/// Creates the game window using the specified width, height
			/// and title.
			/// </summary>
			///
			/// <param name="WIDTH"> The width of the window. </param>
			/// <param name="HEIGHT"> The height of the window. </param>
			/// <param name="TITLE"> A title for the window. </param>
			void makeGameWindow(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE);

			/// <summary> Handles the game's main loop. </summary>
			void mainLoop();

			/// <summary> Adds a new scene to the game. </summary>
			void addScene(std::unique_ptr<Scene> scene);

			/// <summary> Removes a scene from the game. </summary>
			void removeScene();

			/// <summary> Changes the current game scene. </summary>
			void changeScene(std::unique_ptr<Scene> scene);

			/// <summary> Window instance for the game. </summary>
			Window m_gameWindow;
		private:
			float m_deltaTime;
			bool m_debugMode;
			/// <summary> Queue of unique pointers to Scene instances. </summary>
			std::queue<std::unique_ptr<Scene>> m_scene_queue;
			sf::Clock m_clock;
			Logger m_logger;
	};
}

#endif