#include "../include/Window.h"

void PhinyxEngine::Window::init(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, bool showDebugPane) {
	logger.log("DEBUG", "Creating render window.");
	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), TITLE);
	m_WIDTH = WIDTH;
	m_HEIGHT = HEIGHT;
	m_TITLE = TITLE;
	m_showDebugPane = showDebugPane;
	m_debugPane = sf::RectangleShape(sf::Vector2f(250.0f, 150.0f));
	m_debugPane.setFillColor(sf::Color::White);
}

void PhinyxEngine::Window::clear() {
	m_window->clear();
}

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

void PhinyxEngine::Window::drawRect(sf::RectangleShape rect) {
	m_window->draw(rect);
}

void PhinyxEngine::Window::drawRectVector(std::vector<sf::RectangleShape> rectVector) {
	for (int i = 0; i < rectVector.size(); i++) {
		m_window->draw(rectVector[i]);
	}
}

void PhinyxEngine::Window::drawText(sf::Text text) {
	m_window->draw(text);
}

void PhinyxEngine::Window::handleEvents() {
	sf::Event sfEvent;

	while (m_window->pollEvent(sfEvent)) {
		switch (sfEvent.type) {
			case sf::Event::Closed:
				logger.log("DEBUG", "Closing render window.");
				m_window->close();
				break;
		}
	}
}

bool PhinyxEngine::Window::isOpen() {
	return m_window->isOpen();
}

unsigned int PhinyxEngine::Window::getWidth() {
	return m_WIDTH;
}

unsigned int PhinyxEngine::Window::getHeight() {
	return m_HEIGHT;
}

std::string PhinyxEngine::Window::getTitle() {
	return m_TITLE;
}