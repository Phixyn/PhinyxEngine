#include "include/Window.h"

void PhinyxEngine::Window::init() {
	window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), TITLE);
}

void PhinyxEngine::Window::clear() {
	window->clear();
}

void PhinyxEngine::Window::render() {
	window->display();
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