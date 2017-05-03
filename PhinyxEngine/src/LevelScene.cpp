#include "../include/LevelScene.hpp"
#include "../include/Game.hpp"
#include "../include/EnemyMonster.hpp"
#include <fstream>

/// <summary>
/// Constructor for the class. Initializes the member variables for the LevelScene
/// in an initializer statement (?) and calls methods to parse the level and level
/// data files.
/// </summary>
PhinyxEngine::LevelScene::LevelScene(Game &game, std::string levelFilePath, std::string dataFilePath) :
		Scene(game), m_player(100, 20, 150.0f, 54.0f)
{
	m_levelFilePath = levelFilePath;
	m_dataFilePath = dataFilePath;
	parseDataFile();
	parseLevelFile();
}

PhinyxEngine::LevelScene::LevelScene(Game & game, std::string levelFilePath, std::string dataFilePath, std::string backgroundImagePath) :
	Scene(game), m_player(100, 20, 150.0f, 54.0f)
{
	m_levelFilePath = levelFilePath;
	m_dataFilePath = dataFilePath;
	parseDataFile();
	parseLevelFile();
	setBackgroundImage(backgroundImagePath);
}

/// <summary>
/// Parses the level's data file which specifies the textures for
/// all the entities specified in the level file.
/// Loads the textures found in the file and stores them in a
/// map with the entity ID and its corresponding texture file name.
/// </summary>
void PhinyxEngine::LevelScene::parseDataFile()
{
	std::string fileLine;
	std::ifstream dataFile;
	dataFile.open(m_dataFilePath);

	if (!dataFile.is_open())
		m_logger.log("ERROR", "Unable to open level data file.");

	else
	{
		while (std::getline(dataFile, fileLine))
		{
			if (fileLine.find('=') != std::string::npos)
			{
				std::vector<std::string> lineSplitVector = PhinyxEngine::Util::stringSplit(fileLine, '=');
				std::string textureID = lineSplitVector[0];
				std::string textureFileName = lineSplitVector[1];
				sf::Texture textureToLoad;
				textureToLoad.loadFromFile(textureFileName);
				m_logger.log("INFO", "Loaded texture file: " + textureFileName);
				// Add entity ID (e.g. "1") and texture file name (e.g. "grass.png") to map
				m_levelTextures.insert(std::make_pair(textureID, textureToLoad));
			}
		}
		m_logger.log("INFO", "Loaded level data file: " + m_dataFilePath);
	}
}

/// <summary>
/// Parses the level file which contains all the entities to load.
/// Constructs the entity's RectangleShape and sets its texture.
/// The entity's texture is retrieved from the m_levelTextures map, which is
/// populated in the parseDataFile() method.
/// </summary>
void PhinyxEngine::LevelScene::parseLevelFile()
{
	std::ifstream levelFile;
	levelFile.open(m_levelFilePath);

	if (!levelFile.is_open())
		m_logger.log("ERROR", "Unable to open level file.");

	else
	{
		std::string fileLine;
		std::vector<std::string> fileLines;

		// Read all file lines and store in fileLines vector
		// TODO: Ignore lines that begin with a #
		while (std::getline(levelFile, fileLine))
		{
			fileLines.push_back(fileLine);
		}

		// We will start setting the position for the sprites
		// from the bottom to the top of the screen
		// TODO: Should be replaces with window height but it's not working atm
		// unsigned int row = m_game_ptr->m_gameWindow.getHeight();
		unsigned int row = fileLines.size() - 1;
		// Read file lines from end to beginning
		// Iterate through lines
		for (auto iterator = fileLines.rbegin(); iterator != fileLines.rend(); ++iterator)
		{
			std::vector<std::string> tiles = PhinyxEngine::Util::stringSplit(*iterator, '|');

			// Iterate through tiles in this line
			for (int column = 0; column < tiles.size(); column++)
			{
				if (tiles[column] == "-")
				{
					// Blank tiles
					continue;
				}

				else if (tiles[column] == "0")
				{
					// Player sprite
					m_player.setTexture(&m_levelTextures[tiles[column]]);
					m_logger.log("DEBUG", "Player rect width: " + std::to_string(m_player.m_rectWidth));
					m_logger.log("DEBUG", "Player rect height: " + std::to_string(m_player.m_rectHeight));
					m_logger.log("DEBUG", "Player x: " + std::to_string((column * m_player.m_rectWidth)));
					m_logger.log("DEBUG", "Player y: " + std::to_string((row * m_player.m_rectHeight)));
					m_player.m_rect.setPosition(column * m_textureSize, row * m_textureSize);
					// m_liveEntities.push_back(&m_player);
				}

				else if (tiles[column] == "4")
				{
					// Enemy sprite
					// TODO: This is temporary and should be improved
					// Ideally we should check tiles[column] == "enemy_x"
					EnemyMonster enemy(100, 20);
					enemy.setTexture(&m_levelTextures[tiles[column]]);
					enemy.m_rect.setPosition(column * m_textureSize, row * m_textureSize);
					// m_liveEntities.push_back(&enemy);
				}

				else
				{
					// Create a shape and set its texture based on the data line
					sf::RectangleShape shape(sf::Vector2f(m_textureSize, m_textureSize));
					shape.setTexture(&m_levelTextures[tiles[column]]);
					shape.setPosition(column * m_textureSize, row * m_textureSize);
					// Append a new entity with rect to tileEntities vector
					m_tileEntities.push_back(PhinyxEngine::TileEntity(shape));
				}
			}

			// TODO: can't read window height atm for some reason
			// row -= m_textureSize;
			row -= 1;
		}
		levelFile.close();
		m_logger.log("INFO", "Loaded level file: " + m_levelFilePath);
	}
}

void PhinyxEngine::LevelScene::handleEvents()
{
	m_player.handleEvents();
	// TODO: enemies
}

/// <summary>
/// Checks for collision between the scene's entities.
/// Calls the update methods for the entities.
/// </summary>
void PhinyxEngine::LevelScene::update(float deltaTime)
{
	m_player.update(deltaTime);

	// The direction vector to be used by onCollision
	// The vector is set by handleCollision and used in onCollision to set the
	// entity's velocity according to the direction given by handleCollision
	sf::Vector2f direction;
	for (TileEntity &tile : m_tileEntities)
	{
		// Passing 1.0f as force needed to push the tile. Which means our
		// player can't walk through the wall as they won't have enough force
		// and the tile will always push the player away
		if (tile.getCollision().handleCollision(m_player.getCollision(), direction, 1.0f))
		{
			m_player.onCollision(direction);
		}
	}
	// TODO: enemies

	// Set the center of the game view
	m_game_ptr->m_gameWindow.m_view.setCenter(m_player.m_rect.getPosition());
	// Set the center of the scene's background image based on the view's center
	m_backgroundSprite.setPosition(m_game_ptr->m_gameWindow.m_view.getCenter().x, m_game_ptr->m_gameWindow.m_view.getCenter().y);
}

/// <summary>
/// Draws the scene's entities into the game's window
/// Accesses the game's window via the game pointer member variable
/// </summary>
void PhinyxEngine::LevelScene::draw()
{
	m_game_ptr->m_gameWindow.draw(m_backgroundSprite);
	m_game_ptr->m_gameWindow.drawRect(m_player.m_rect);

	// TODO: liveEntities
	// m_game_ptr->m_gameWindow.drawRect(m_enemy.m_rect);
	/*
	for (LiveEntity* liveEntity : m_liveEntities)
	{
		m_game_ptr->m_gameWindow.drawRect(liveEntity->m_rect);
	}
	*/

	// Draw our tiles
	for (TileEntity &tile : m_tileEntities)
	{
		m_game_ptr->m_gameWindow.drawRect(tile.m_rect);
	}
}

void PhinyxEngine::LevelScene::setBackgroundImage(std::string imageFilePath)
{
	if (!m_backgroundTexture.loadFromFile(imageFilePath))
	{
		m_logger.log("ERROR", "Could not load level background image: " + imageFilePath);
		return;
	}

	// TODO: Handle tileable backgrounds?
	// m_backgroundTexture.setRepeated(true);
	m_backgroundSprite.setTexture(m_backgroundTexture);
	// m_backgroundSprite.setOrigin(m_game_ptr->m_gameWindow.m_view.getCenter().x, m_game_ptr->m_gameWindow.m_view.getCenter().y / 2.0f);
	m_backgroundSprite.setOrigin(m_game_ptr->m_gameWindow.m_view.getCenter());
	m_backgroundSprite.setTextureRect(sf::IntRect(0, 0, m_game_ptr->m_gameWindow.m_view.getSize().x, m_game_ptr->m_gameWindow.m_view.getSize().y));
}