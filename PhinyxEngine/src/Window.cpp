#include "../include/Window.h"

/// <summary>
/// Initializes a new SFML Render Window for rendering 2D graphics.
/// At the moment, a non-resizable window is created as resizing is not
/// properly handled by the engine yet.
/// </summary>
///
/// <param name="WIDTH"> The width of the window. </param>
/// <param name="HEIGHT"> The height of the window. </param>
/// <param name="TITLE"> A title for the window. </param>
/// <param name="showDebugPane"> A title for the window. </param>
void PhinyxEngine::Window::init(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, bool showDebugPane) {
	m_logger.log("DEBUG", "Creating render window.");
	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Close);
	m_window->requestFocus();
	m_hasFocus = true;
	m_WIDTH = WIDTH;
	m_HEIGHT = HEIGHT;
	m_TITLE = TITLE;
	m_showDebugPane = showDebugPane;
	m_debugPane = sf::RectangleShape(sf::Vector2f(250.0f, 150.0f));
	m_debugPane.setFillColor(sf::Color::White);
}

/// <summary>
/// Clears the window by calling the clear method on the SFML Window instance.
/// </summary>
void PhinyxEngine::Window::clear() {
	m_window->clear();
}

/// <summary>
/// Calls the display method of the SFML Window.
/// WIP: If debug pane is enabled, displays a debug pane with helpful information
/// (not yet implemented).
/// </summary>
void PhinyxEngine::Window::render() {
	if (m_showDebugPane == true) {
		m_debugPaneFont.loadFromFile("arial.ttf");

		m_debugTextDeltaTimer.setFont(m_debugPaneFont);
		m_debugTextDeltaTimer.setFillColor(sf::Color::Black);
		m_debugTextDeltaTimer.setCharacterSize(12);
		m_debugTextDeltaTimer.setString("Delta timer: 0");
		drawRect(m_debugPane);
		drawText(m_debugTextDeltaTimer);
	}

	m_window->display();
}

/// <summary> Draws a SFML Rectangle Shape onto the SFML Window. </summary>
void PhinyxEngine::Window::drawRect(sf::RectangleShape rect) {
	m_window->draw(rect);
}

/// <summary>
/// Draws multiple SFML Rectangle Shapes onto the SFML Window (specified in a vector)
/// </summary>
void PhinyxEngine::Window::drawRectVector(std::vector<sf::RectangleShape> rectVector) {
	for (int i = 0; i < rectVector.size(); i++) {
		m_window->draw(rectVector[i]);
	}
}

/// <summary> Draws an SFML Text object onto the SFML Window. </summary>
void PhinyxEngine::Window::drawText(sf::Text text) {
	m_window->draw(text);
}

/// <summary> Polls the SFML Window for events and handles them appropriately. </summary>
void PhinyxEngine::Window::handleEvents() {
	sf::Event sfEvent;

	while (m_window->pollEvent(sfEvent)) {
		switch (sfEvent.type) {
			case sf::Event::Closed:
				m_logger.log("DEBUG", "Closing render window.");
				m_window->close();
				break;
			case sf::Event::LostFocus:
				m_logger.log("DEBUG", "Lost window focus.");
				m_hasFocus = false;
				break;
			case sf::Event::GainedFocus:
				m_logger.log("DEBUG", "Gained window focus.");
				m_hasFocus = true;
				break;
		}
	}
}

/// <summary> Returns a boolean indicating if the window is open, by calling SFML's Window isOpen method. </summary>
bool PhinyxEngine::Window::isOpen() {
	return m_window->isOpen();
}

/// <summary> Returns a boolean indicating if the window has focus. This member variable set in handleEvents() method. </summary>
bool PhinyxEngine::Window::hasFocus() {
	return m_hasFocus;
}

/// <summary> Returns the width of the window (TODO: should this be a float?) </summary>
unsigned int PhinyxEngine::Window::getWidth() {
	return m_WIDTH;
}

/// <summary> Returns the height of the window (TODO: should this be a float?) </summary>
unsigned int PhinyxEngine::Window::getHeight() {
	return m_HEIGHT;
}

/// <summary> Returns the title of the window. </summary>
std::string PhinyxEngine::Window::getTitle() {
	return m_TITLE;
}