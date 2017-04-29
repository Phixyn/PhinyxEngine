#include "include/Game.h"

PhinyxEngine::Game::Game() {
	gameWindow.init();
}

void PhinyxEngine::Game::mainLoop() {
	while (gameWindow.isOpen()) {
		gameWindow.pollForEvents();
		gameWindow.clear();
		gameWindow.render();
	}
}