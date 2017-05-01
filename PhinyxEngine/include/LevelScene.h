#ifndef LEVEL_SCENE_H
#define LEVEL_SCENE_H

#include "Scene.h"
#include "Player.h"
#include "TileEntity.h"
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

			float m_textureSize = 48;
			std::string m_levelFilePath;
			std::string m_dataFilePath;
			std::vector<PhinyxEngine::TileEntity> m_tileEntities;
			std::vector<PhinyxEngine::LiveEntity> m_liveEntities;
			// std::vector<sf::RectangleShape> m_tileSprites;
			std::map<std::string, sf::Texture> m_levelTextures;

			Player m_player;
			Logger m_logger;
	};
}

#endif