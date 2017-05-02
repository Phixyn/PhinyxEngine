#ifndef LEVEL_SCENE_H
#define LEVEL_SCENE_H

#include "Scene.h"
#include "Player.h"
#include "TileEntity.h"
#include "Util.h"
#include "Logger.h"
#include <SFML/Graphics.hpp>

namespace PhinyxEngine
{
	class LevelScene : public Scene
	{
		public:
			/// <summary> Default constructor. </summary>
			///
			/// <param name="game"> A pointer to an instance of the Game
			/// class. </param>
			/// <param name="levelFilePath"> A string containing the path for the
			/// level file. </param>
			/// <param name="dataFilePath"> A string containing the path for the
			/// level's data file. </param>
			LevelScene(Game &game, std::string levelFilePath, std::string dataFilePath);
			/// <summary> Handles events specific to the level
			/// scenes. </summary>
			void handleEvents() override;
			/// <param name="deltaTime"> The delta time for the update
			/// frequency rate. </param>
			void update(float deltaTime) override;
			/// <summary> Draws the level scene. </summary>
			void draw() override;
		private:
			/// <summary> Parses the level's data file. </summary>
			void parseDataFile();
			/// <summary> Parses the level's map file. </summary>
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