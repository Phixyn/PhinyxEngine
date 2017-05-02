#include "../include/Game.h"

/// <summary> Constructor for the class. </summary>
/// <param name="debug"> A boolean specifying if the game is to be run in debug mode. </param>
PhinyxEngine::Game::Game(bool debug) {
	m_logger.log("INFO", "Initializing game.");
	m_debugMode = debug;
}

/// <summary> Creates the game window using the specified width, height and title. </summary>
///
/// <param name="WIDTH"> The width of the window. </param>
/// <param name="HEIGHT"> The height of the window. </param>
/// <param name="TITLE"> A title for the window. </param>
void PhinyxEngine::Game::makeGameWindow(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE) {
	m_logger.log("DEBUG", "Making game window.");
	m_gameWindow.init(WIDTH, HEIGHT, TITLE, m_debugMode);
}

/// <summary> Handles the game's main loop (list the steps) </summary>
void PhinyxEngine::Game::mainLoop() {
	m_logger.log("DEBUG", "Entering main loop.");
	while (m_gameWindow.isOpen()) {

		m_deltaTime = m_clock.restart().asSeconds();
		// Limit framerate to 60
		if (m_deltaTime > 1.0f / 60.0f) {
			m_deltaTime = 1.0f / 60.0f;
		}

		// Handle window events
		m_gameWindow.handleEvents();
		// Clear game window
		m_gameWindow.clear();
		// Only handle events and update if we have focus on our window
		if (m_gameWindow.hasFocus()) {
			// Handle scene events
			m_scene_queue.front()->handleEvents();
			// Update scene
			m_scene_queue.front()->update(m_deltaTime);
		}
		// (Re)draw scene
		m_scene_queue.front()->draw();
		// Render window
		m_gameWindow.render();
	}
	m_logger.log("DEBUG", "Exited main loop.");
}

/// <summary> Adds a pointer to a scene to the game's scene queue pointer vector (?) </summary>
void PhinyxEngine::Game::addScene(std::unique_ptr<Scene> scene) {
	m_scene_queue.push(std::move(scene));
}

/// <summary> Removes a scene from the game </summary>
void PhinyxEngine::Game::removeScene() {
	m_scene_queue.pop();
}

/// <summary> Changes to a new scene by removing the top scene and adding a new scene (?) </summary>
void PhinyxEngine::Game::changeScene(std::unique_ptr<Scene> scene) {
	removeScene();
	addScene(std::move(scene));
}