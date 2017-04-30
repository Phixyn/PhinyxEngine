#include "Game.h"

int main() {
	PhinyxEngine::Game game(true);
	game.makeGameWindow(600, 480, "Phinyx Engine Demo");
	game.mainLoop();
}