#ifndef LEVEL_SCENE_H
#define LEVEL_SCENE_H

#include "InfoPanel.hpp"
#include "PlayerEntity.hpp"
#include "Scene.hpp"
#include "TileEntity.hpp"

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
			/// Overloaded constructor taking an additional argument
			/// for a reference to a
			/// <see cref="PlayerEntity">PlayerEntity</see> object.
			/// </summary>
			///
			/// <param name="game">
			/// A pointer to a <see cref="Game">Game</see> object, used to
			/// access game properties and methods.
			/// </param>
			/// <param name="player">
			/// A pointer to a <see cref="PlayerEntity">PlayerEntity</see>
			/// object, used to access player properties and methods.
			/// </param>
			/// <param name="backgroundImagePath">
			/// A string containing the path for the background image file.
			/// </param>
			// LevelScene(Game &game, PlayerEntity &player, std::string backgroundImagePath);
			// The above constructor is from our SFML Game AI demos project, not sure if we
			// can make it work in this project.

			/// <summary>
			/// Default class destructor.
			/// </summary>
			~LevelScene() { }

			/// <summary>
			/// Handles events specific to the level scene.
			/// </summary>
			///
			/// <param name="sfEvent">
			/// A SFML event (e.g. generated user input) object.
			/// </param>
			void handleEvents(sf::Event sfEvent) override;

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

			// TODO: Implement these (they are from the SFML Game AI demos project)
			/// <summary>
			/// Spawns a new live entity in the level scene and adds it to the
			/// <see cref="m_liveEntities">m_liveEntities</see> vector.
			/// </summary>
			///
			/// <param name="entity">
			/// Instance of <see cref="LiveEntity">LiveEntity</see> to be added
			/// to the level scene.
			/// </param>
			///
			/// <seealso cref="LiveEntity" />
			void spawnLiveEntity(LiveEntity &entity); // TODO: Implement this
			/// <summary>
			/// Spawns a new live entity in the level scene and adds it to the
			/// m_liveEntities vector.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the live entity.
			/// </param>
			/// <param name="size">
			/// A SFML Vector2f containing the live entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the entity's position on the
			/// game scene.
			/// </param>
			///
			/// <seealso cref="LiveEntity" />
			void spawnLiveEntity(int health, sf::Vector2f size, sf::Vector2f position); // TODO: Implement this
			/// <summary>
			/// Spawns a new live entity in the level scene and adds it to the
			/// m_liveEntities vector.
			/// </summary>
			///
			/// <param name="health">
			/// The health points of the live entity.
			/// </param>
			/// <param name="size">
			/// A SFML Vector2f containing the live entity's size.
			/// </param>
			/// <param name="position">
			/// A SFML Vector2f containing the entity's position on the
			/// game scene.
			/// </param>
			/// <param name="speed">
			/// The movement speed of the live entity.
			/// </param>
			///
			/// <seealso cref="LiveEntity" />
			void spawnLiveEntity(int health, sf::Vector2f size, sf::Vector2f position, float speed); // TODO: Implement this
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
			std::vector<PhinyxEngine::TileEntity*> m_tileEntities;
			/// <summary>
			/// Vector containing <see cref="LiveEntity">LiveEntity</see>
			/// objects present in the scene.
			/// </summary>
			///
			/// <seealso cref="Entity" />
			/// <seealso cref="LiveEntity" />
			std::vector<PhinyxEngine::LiveEntity*> m_liveEntities;
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
			/// A pointer to a <see cref="PlayerEntity">PlayerEntity</see>
			/// object, necessary to access information about the player
			/// (such as its position), in order to draw or update them in
			/// the scene.
			/// </summary>
			///
			/// <seealso cref="PlayerEntity" />
			// PlayerEntity* m_playerEntity;

			/// <summary>
			/// An instance of <see cref="PlayerEntity">PlayerEntity</see>
			/// used to get and set from the PlayerEntity (such as its position),
			/// and draw or update them in the scene.
			/// </summary>
			///
			/// <seealso cref="PlayerEntity" />
			PlayerEntity m_playerEntity;

			/// <summary>
			/// Instance of <see cref="Logger">Logger</see> for logging.
			/// </summary>
			Logger m_logger;
	};
}

#endif