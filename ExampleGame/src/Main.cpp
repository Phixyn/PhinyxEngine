#include "Game.hpp"
#include "LevelScene.hpp"
#include <memory>

int main() {
	PhinyxEngine::Game game(800, 600, "Phinyx Engine Demo", false);
	game.addScene(std::make_unique<PhinyxEngine::LevelScene>(game, "data/example.lvl", "data/example.dat", "assets/background.png"));
	game.mainLoop();
}