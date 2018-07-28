#ifndef LEVEL_SCENE_H
#define LEVEL_SCENE_H

#include "Scene.hpp"
#include "Player.hpp"
#include "TileEntity.hpp"
#include "Util.hpp"
#include "Logger.hpp"
#include <SFML/Graphics.hpp>

namespace PhinyxEngine
{
	/// <summary>
	/// Subclass of <see cref="Scene">Scene</see> for game levels.
	/// </summary>
	class LevelScene : public Scene
	{
		public:
			/// <summary>
			/// Default constructor taking arguments for a reference to
			/// <see cref="Game">Game</see> and strings containing the file
			/// paths for the level data files.
			/// </summary>
			///
			/// <param name="game">
			/// A pointer to a <see cref="Game">Game</see> object, used to
			/// access game properties and methods.
			/// </param>
			/// <param name="levelFilePath">
			/// A string containing the path for the level file.
			/// </param>
			/// <param name="dataFilePath">
			/// A string containing the path for the level's data file.
			/// </param>
			LevelScene(Game &game, std::string levelFilePath, std::string dataFilePath);

			/// <summary>
			/// Overloaded constructor with a parameter for the scene's
			/// background image.
			/// </summary>
			///
			/// <param name="game">
			/// A pointer to an instance of the Game class.
			/// </param>
			/// <param name="levelFilePath">
			/// A string containing the path for the level file.
			/// </param>
			/// <param name="dataFilePath">
			/// A string containing the path for the level's data file.
			/// </param>
			/// <param name="backgroundImagePath">
			/// A string containing the path for the background image file.
			/// </param>
			LevelScene(Game &game, std::string levelFilePath, std::string dataFilePath, std::string backgroundImagePath);

			/// <summary>
			/// Default class destructor.
			/// </summary>
			~LevelScene() { }

			/// <summary>
			/// Handles events specific to the level scene.
			/// </summary>
			void handleEvents() override;

			/// <summary>
			/// Updates the level scene.
			/// </summary>
			///
			/// <param name="deltaTime">
			/// The delta time for the update frequency rate.
			/// </param>
			void update(float deltaTime) override;

			/// <summary>
			/// Draws the level scene.
			/// </summary>
			void draw() override;

			/// <summary>
			/// Sets the scene's background image.
			/// </summary>
			///
			/// <param name="imageFilePath">
			/// A string containing the path for the level's background
			/// image file.
			/// </param>
			void setBackgroundImage(std::string imageFilePath);
		private:
			/// <summary>
			/// Parses the level's data file.
			/// </summary>
			void parseDataFile();
			/// <summary>
			/// Parses the level's map file.
			/// </summary>
			void parseLevelFile();

			/// <summary>
			/// Size (in pixels) of the textures used by sprites in the scene.
			/// </summary>
			float m_textureSize = 48;
			/// <summary>
			/// TODO
			/// </summary>
			std::string m_levelFilePath;
			/// <summary>
			/// TODO
			/// </summary>
			std::string m_dataFilePath;

			/// <summary>
			/// TODO
			/// </summary>
			std::vector<PhinyxEngine::TileEntity> m_tileEntities;
			/// <summary>
			/// Vector containing <see cref="LiveEntity">LiveEntity</see>
			/// objects present in the scene.
			/// </summary>
			///
			/// <seealso cref="Entity" />
			/// <seealso cref="LiveEntity" />
			std::vector<PhinyxEngine::LiveEntity> m_liveEntities;
			// std::vector<sf::RectangleShape> m_tileSprites;
			/// <summary>
			/// Map containing entries with an ID of a texture and an instance
			/// of SFML Texture.
			/// </summary>
			std::map<std::string, sf::Texture> m_levelTextures;

			/// <summary>
			/// SFML Texture object for the level's background texture.
			/// </summary>
			sf::Texture m_backgroundTexture;
			/// <summary>
			/// SFML Sprite object for the level's background sprite.
			/// </summary>
			sf::Sprite m_backgroundSprite;

			/// <summary>
			/// An instance of <see cref="PlayerEntity">PlayerEntity</see>
			/// used to get and set from the PlayerEntity (such as its position),
			/// and draw or update them in the scene.
			/// </summary>
			///
			/// <seealso cref="PlayerEntity" />
			Player m_player;

			/// <summary>
			/// Instance of <see cref="Logger">Logger</see> for logging.
			/// </summary>
			Logger m_logger;
	};
}

#endif