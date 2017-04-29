#include "include/Game.h"
#include <iostream>

PhinyxEngine::Game::Game(bool debug) {
	debugMode = debug;
	gameWindow.init();
	addScene(std::make_unique<PhinyxEngine::LevelScene>(this));
}

void PhinyxEngine::Game::mainLoop() {
	while (gameWindow.isOpen()) {

		deltaTime = clock.restart().asSeconds();
		std::cout << "Setting delta time to " << deltaTime << std::endl;

		gameWindow.pollForEvents();
		// clear game window
		gameWindow.clear();
		// handle user input
		m_scene_queue.front()->input();
		// update scene
		m_scene_queue.front()->update(deltaTime);
		// (re)draw scene
		m_scene_queue.front()->draw();
		// render window
		gameWindow.render();
	}
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