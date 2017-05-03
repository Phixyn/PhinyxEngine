#include "../include/Window.h"

/// <summary>
/// Initializes a new SFML Render Window for rendering 2D graphics.
/// At the moment, a non-resizable window is created as resizing is not
/// properly handled by the engine yet.
/// </summary>
PhinyxEngine::Window::Window(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, bool showDebugPane) :
	m_view(sf::Vector2f(WIDTH / 2.0f, HEIGHT / 2.0f), sf::Vector2f((float)WIDTH, (float)HEIGHT))
{
	m_WIDTH = WIDTH;
	m_HEIGHT = HEIGHT;
	m_TITLE = TITLE;
	m_showDebugPane = showDebugPane;

	m_logger.log("DEBUG", "Creating render window.");
	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Close);
	m_window->requestFocus();
	m_hasFocus = true;

	// TODO: Debug panel
	m_debugPane = sf::RectangleShape(sf::Vector2f(250.0f, 150.0f));
	m_debugPane.setFillColor(sf::Color::White);
}

void PhinyxEngine::Window::clear()
{
	m_window->clear();
}

/// <summary>
/// WIP: If debug pane is enabled, displays a debug pane with helpful information
/// (not yet implemented).
/// </summary>
void PhinyxEngine::Window::render()
{
	if (m_showDebugPane == true)
	{
		m_debugPaneFont.loadFromFile("arial.ttf");

		m_debugTextDeltaTimer.setFont(m_debugPaneFont);
		m_debugTextDeltaTimer.setFillColor(sf::Color::Black);
		m_debugTextDeltaTimer.setCharacterSize(12);
		m_debugTextDeltaTimer.setString("Delta timer: 0");
		drawRect(m_debugPane);
		drawText(m_debugTextDeltaTimer);
	}

	// Reset the view
	m_window->setView(m_view);
	m_window->display();
}

void PhinyxEngine::Window::draw(const sf::Drawable &drawable)
{
	m_window->draw(drawable);
}

void PhinyxEngine::Window::drawRect(sf::RectangleShape rect)
{
	m_window->draw(rect);
}

void PhinyxEngine::Window::drawRectVector(std::vector<sf::RectangleShape> rectVector)
{
	for (int i = 0; i < rectVector.size(); i++)
	{
		m_window->draw(rectVector[i]);
	}
}

void PhinyxEngine::Window::drawText(sf::Text text)
{
	m_window->draw(text);
}

// TODO not working as intended
void PhinyxEngine::Window::resizeView(sf::Window &window, sf::View &view)
{
	float aspectRatio = (float)window.getSize().x / (float)window.getSize().y;
	view.setSize(m_WIDTH * aspectRatio, m_HEIGHT);
}

/// <summary> Polls the SFML Window for events and handles them appropriately. </summary>
void PhinyxEngine::Window::handleEvents()
{
	sf::Event sfEvent;

	while (m_window->pollEvent(sfEvent))
	{
		switch (sfEvent.type)
		{
			case sf::Event::Closed:
				m_logger.log("DEBUG", "Closing render window.");
				m_window->close();
				break;
			case sf::Event::LostFocus:
				m_hasFocus = false;
				break;
			case sf::Event::GainedFocus:
				m_hasFocus = true;
				break;
		}
	}
}

/// <summary> Returns the result of SFML's Window isOpen method. </summary>
/// <returns> A boolean indicating if the window is open. </returns>
bool PhinyxEngine::Window::isOpen()
{
	return m_window->isOpen();
}

bool PhinyxEngine::Window::hasFocus()
{
	return m_hasFocus;
}

unsigned int PhinyxEngine::Window::getWidth()
{
	return m_WIDTH;
}

unsigned int PhinyxEngine::Window::getHeight()
{
	return m_HEIGHT;
}

std::string PhinyxEngine::Window::getTitle()
{
	return m_TITLE;
}