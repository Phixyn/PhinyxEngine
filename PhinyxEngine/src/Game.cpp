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
		// m_logger.log("DEBUG", "Setting delta time to " + std::to_string(m_deltaTime));

		m_gameWindow.handleEvents();
		// clear game window
		m_gameWindow.clear();
		// handle user input
		m_scene_queue.front()->handleEvents();
		// update scene
		m_scene_queue.front()->update(m_deltaTime);
		// (re)draw scene
		m_scene_queue.front()->draw();
		// render window
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