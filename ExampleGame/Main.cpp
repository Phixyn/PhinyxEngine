#include "Game.h"
#include "LevelScene.h"
#include <memory>

int main() {
	PhinyxEngine::Game game(false);
	game.addScene(std::make_unique<PhinyxEngine::LevelScene>(game, "example.lvl", "example.dat"));

	game.makeGameWindow(600, 480, "Phinyx Engine Demo");
	game.mainLoop();
}