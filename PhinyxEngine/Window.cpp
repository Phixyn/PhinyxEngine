#include "include/Window.h"

void PhinyxEngine::Window::init(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE, bool showDebugPane) {
	window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), TITLE);
	m_WIDTH = WIDTH;
	m_HEIGHT = HEIGHT;
	m_TITLE = TITLE;
	m_showDebugPane = showDebugPane;
	debugPane = sf::RectangleShape(sf::Vector2f(250.0f, 150.0f));
	debugPane.setFillColor(sf::Color::White);
}

void PhinyxEngine::Window::clear() {
	window->clear();
}

void PhinyxEngine::Window::render() {
	if (m_showDebugPane == true) {
		debugPaneFont.loadFromFile("arial.ttf");

		debugTextDeltaTimer.setFont(debugPaneFont);
		debugTextDeltaTimer.setFillColor(sf::Color::Black);
		debugTextDeltaTimer.setCharacterSize(12);
		debugTextDeltaTimer.setString("Delta timer: 0");
		drawRect(debugPane);
		drawText(debugTextDeltaTimer);
	}

	window->display();
}

void PhinyxEngine::Window::drawRect(sf::RectangleShape rect) {
	window->draw(rect);
}

void PhinyxEngine::Window::drawText(sf::Text text) {
	window->draw(text);
}

void PhinyxEngine::Window::pollForEvents() {
	sf::Event evt;

	while (window->pollEvent(evt)) {
		if (evt.type == sf::Event::Closed) {
			window->close();
		}
	}
}

bool PhinyxEngine::Window::isOpen() {
	return window->isOpen();
}