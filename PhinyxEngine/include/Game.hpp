#ifndef GAME_H
#define GAME_H

#include "Window.hpp"
#include "Scene.hpp"
#include <queue>

/// <summary>
/// Namespace for the game engine. Contains all the classes required for
/// making a game, managing scenes, entities, player character and more.
/// </summary>
namespace PhinyxEngine
{
	/// <summary>
	/// Main game class used to initialize the game, create a game window
	/// and add scenes to it.
	/// </summary>
	class Game
	{
		public:
			/// <summary>
			/// <para> Default constructor. </para>
			/// <para> Initializes the Game instance and member variables. </para>
			/// </summary>
			///
			/// <param name="WIDTH"> The width of the game window. </param>
			/// <param name="HEIGHT"> The height of the game window. </param>
			/// <param name="TITLE"> A title for the game window. </param>
			/// <param name="debug"> A boolean specifying whether the game is
			/// to be run in debug mode. </param>
			Game(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, bool debug);

			/// <summary>
			/// Default class destructor.
			/// </summary>
			~Game() { }

			/// <summary>
			/// <para> Performs the game's main loop. </para>
			/// <para> Handles user input, updates game state and renders
			/// the game scene. </para>
			/// </summary>
			void mainLoop();

			/// <summary>
			/// Adds a new scene to the game.
			/// </summary>
			///
			/// <param name="scene">
			/// A unique pointer to a <see cref="Scene">Scene</see> object.
			/// </param>
			///
			/// <seealso cref="Scene" />
			void addScene(std::unique_ptr<Scene> scene);
			/// <summary>
			/// Removes a scene from the game.
			/// </summary>
			///
			/// <seealso cref="Scene" />
			void removeScene();
			/// <summary>
			/// Changes the current scene in the game.
			/// </summary>
			///
			/// <param name="scene">
			/// A unique pointer to a <see cref="Scene">Scene</see> object.
			/// </param>
			///
			/// <seealso cref="Scene" />
			void changeScene(std::unique_ptr<Scene> scene);

			/// <summary>
			/// <see cref="Window">Window</see> object for the game.
			/// </summary>
			Window m_gameWindow;
		private:
			/// <summary>
			/// The delta time for the game's update frequency rate.
			/// </summary>
			float m_deltaTime;
			/// <summary>
			/// Boolean specifying if the game is running in debug mode.
			/// </summary>
			bool m_debugMode;
			/// <summary>
			/// Queue of unique pointers to <see cref="Scene">Scene</see>
			/// objects.
			/// </summary>
			std::queue<std::unique_ptr<Scene>> m_sceneQueue;
			/// <summary>
			/// TODO
			/// </summary>
			sf::Clock m_clock;
			/// <summary>
			/// Instance of <see cref="Logger">Logger</see> for logging.
			/// </summary>
			Logger m_logger;
	};
}

#endif