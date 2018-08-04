#include "../include/Game.hpp"

PhinyxEngine::Game::Game(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, bool debug) :
	m_gameWindow(WIDTH, HEIGHT, TITLE, m_debugMode)
{
	m_logger.log("INFO", "Initializing game.");
	m_debugMode = debug;
}

void PhinyxEngine::Game::mainLoop()
{
	m_logger.log("DEBUG", "Entering main loop.");
	while (m_gameWindow.isOpen())
	{
		// (Re)start the clock and get the time elapsed since clock started,
		// as seconds
		m_deltaTime = m_clock.restart().asSeconds();
		// Limit framerate to 60
		if (m_deltaTime > 1.0f / 60.0f)
			m_deltaTime = 1.0f / 60.0f;

		// Handle window events
		m_gameWindow.handleEvents();
		// Clear game window
		m_gameWindow.clear();
		// Before we continue with the main loop, we should check if the
		// scene queue has items. Attempting to access an empty queue
		// could be bad.
		// TODO: Test this
		/*if (m_sceneQueue.empty())
		{
			m_logger.log("CRITICAL", "Game has no scenes. Unable to continue game main loop. Please add a scene to the game.");
			exit(1);
		}*/
		// Only handle events and update if we have focus on our window
		if (m_gameWindow.hasFocus())
		{
			// Handle scene events
			m_sceneQueue.front()->handleEvents();
			// Update scene
			m_sceneQueue.front()->update(m_deltaTime);
		}
		// (Re)draw scene
		m_sceneQueue.front()->draw();
		// Render window
		m_gameWindow.render();
	}
	m_logger.log("DEBUG", "Exited main loop.");
}

/// <summary>
/// <para> Adds a pointer to a <see cref="Scene">Scene</see> object to the
/// game's scene pointer queue. std::move() is used as to not push a copy
/// of the pointer, but rather the pointer itself. </para>
/// </summary>
void PhinyxEngine::Game::addScene(std::unique_ptr<Scene> scene)
{
	m_logger.log("DEBUG", "Adding new scene to game.");
	m_sceneQueue.push(std::move(scene));
}

/// <summary>
/// <para> Calls pop() on the <see cref="Scene">Scene</see> pointer queue. </para>
/// </summary>
void PhinyxEngine::Game::removeScene()
{
	if (!m_sceneQueue.empty())
	{
		m_logger.log("DEBUG", "Removing a scene from game.");
		m_sceneQueue.pop();
	}
	else
	{
		m_logger.log("ERROR", "Could not remove scene from game: scene queue is empty.");
		return;
	}
}

/// <summary>
/// <para> Changes to a new scene in the game by removing the top scene and
/// adding a new scene to the queue. </para>
/// </summary>
void PhinyxEngine::Game::changeScene(std::unique_ptr<Scene> scene)
{
	m_logger.log("DEBUG", "Changing game scene.");
	removeScene();
	addScene(std::move(scene));
}