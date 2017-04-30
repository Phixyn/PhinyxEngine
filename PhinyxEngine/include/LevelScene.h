#ifndef LEVEL_SCENE_H
#define LEVEL_SCENE_H

#include "Scene.h"
#include "Util.h"
#include <SFML/Graphics.hpp>

namespace PhinyxEngine {
	class LevelScene : public Scene {
		public:
			LevelScene(Game &game, std::string levelFile, std::string dataFile);
			void input() override;
			void update(float dt) override;
			void draw() override;
		private:
			void parseDataFile();
			void parseLevelFile();

			std::string m_levelFilePath;
			std::string m_dataFilePath;
			std::vector<sf::RectangleShape> m_sprites;
	};
}

#endif