#ifndef LEVEL_SCENE_H
#define LEVEL_SCENE_H

#include "Scene.h"
#include <SFML/Graphics.hpp>

namespace PhinyxEngine {
	class LevelScene : public Scene {
		public:
			LevelScene(Game &game);
			void input() override;
			void update(float dt) override;
			void draw() override;
		private:
			sf::RectangleShape debugPane;
			sf::Text debugTextDeltaTimer;
			sf::Font debugPaneFont;
	};
}

#endif
