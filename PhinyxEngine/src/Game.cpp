#include "../include/Game.h"

PhinyxEngine::Game::Game(bool debug) {
	m_logger.log("INFO", "Initializing game.");
	m_debugMode = debug;
}

void PhinyxEngine::Game::makeGameWindow(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE) {
	m_logger.log("DEBUG", "Making game window.");
	m_gameWindow.init(WIDTH, HEIGHT, TITLE, m_debugMode);
}

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

void PhinyxEngine::Game::addScene(std::unique_ptr<Scene> scene) {
	m_scene_queue.push(std::move(scene));
}

void PhinyxEngine::Game::removeScene() {
	m_scene_queue.pop();
}

void PhinyxEngine::Game::changeScene(std::unique_ptr<Scene> scene) {
	removeScene();
	addScene(std::move(scene));
}