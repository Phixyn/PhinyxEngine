#include "include/Window.h"

void PhinyxEngine::Window::init(const unsigned int WIDTH, const unsigned int HEIGHT, const std::string TITLE) {
	window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), TITLE);
	m_WIDTH = WIDTH;
	m_HEIGHT = HEIGHT;
	m_TITLE = TITLE;
}

void PhinyxEngine::Window::clear() {
	window->clear();
}

void PhinyxEngine::Window::render() {
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