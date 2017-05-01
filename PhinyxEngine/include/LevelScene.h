#ifndef LEVEL_SCENE_H
#define LEVEL_SCENE_H

#include "Scene.h"
#include "Player.h"
#include "Util.h"
#include "Logger.h"
#include <SFML/Graphics.hpp>

namespace PhinyxEngine {
	class LevelScene : public Scene {
		public:
			LevelScene(Game &game, std::string levelFile, std::string dataFile);
			void handleEvents() override;
			void update(float deltaTime) override;
			void draw() override;
		private:
			void parseDataFile();
			void parseLevelFile();

			unsigned int m_textureSize = 48;
			std::string m_levelFilePath;
			std::string m_dataFilePath;
			std::vector<sf::RectangleShape> m_sprites;
			std::map<std::string, sf::Texture> m_levelTextures;

			Player m_player;
			Logger logger;
	};
}

#endif