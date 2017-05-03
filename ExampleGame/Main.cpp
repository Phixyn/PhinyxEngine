#include "Game.h"
#include "LevelScene.h"
#include <memory>

int main() {
	PhinyxEngine::Game game(800, 600, "Phinyx Engine Demo", false);
	game.addScene(std::make_unique<PhinyxEngine::LevelScene>(game, "example.lvl", "example.dat", "background.png"));
	game.mainLoop();
}