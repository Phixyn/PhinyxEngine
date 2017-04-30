#include "../include/Game.h"

PhinyxEngine::Game::Game(bool debug) {
	logger.log("INFO", "Initializing game.");
	m_debugMode = debug;
}

void PhinyxEngine::Game::makeGameWindow(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE) {
	logger.log("DEBUG", "Making game window.");
	m_gameWindow.init(WIDTH, HEIGHT, TITLE, m_debugMode);
}

void PhinyxEngine::Game::mainLoop() {
	logger.log("DEBUG", "Entering main loop.");
	while (m_gameWindow.isOpen()) {

		m_deltaTime = m_clock.restart().asSeconds();
		// logger.log("DEBUG", "Setting delta time to " + std::to_string(m_deltaTime));

		m_gameWindow.pollForEvents();
		// clear game window
		m_gameWindow.clear();
		// handle user input
		m_scene_queue.front()->input();
		// update scene
		m_scene_queue.front()->update(m_deltaTime);
		// (re)draw scene
		m_scene_queue.front()->draw();
		// render window
		m_gameWindow.render();
	}
	logger.log("DEBUG", "Exited main loop.");
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