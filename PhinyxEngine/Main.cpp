#include <iostream>
#include <SFML/Graphics.hpp>

const int VELOCITY = 13;

void moveObject(sf::RectangleShape &object, int maxX, int maxY, int posX, int posY) {

}

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Phinyx Engine Demo");
	sf::RectangleShape shape(sf::Vector2f(40, 80));
	shape.setFillColor(sf::Color::Blue);

	std::cout << window.getSize().x << std::endl;
	std::cout << window.getSize().y << std::endl;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					if (shape.getPosition().y > 0) {
						shape.setPosition(shape.getPosition().x, shape.getPosition().y - VELOCITY);
					}
				}
				if (event.key.code == sf::Keyboard::A)
				{
					if (shape.getPosition().x > 0) {
						shape.setPosition(shape.getPosition().x - VELOCITY, shape.getPosition().y);
					}
				}
				if (event.key.code == sf::Keyboard::S)
				{
					if (shape.getPosition().y < window.getSize().y - shape.getSize().y) {
						shape.setPosition(shape.getPosition().x, shape.getPosition().y + VELOCITY);
					}
				}
				if (event.key.code == sf::Keyboard::D)
				{
					if (shape.getPosition().x < window.getSize().x - shape.getSize().x) {
						shape.setPosition(shape.getPosition().x + VELOCITY, shape.getPosition().y);
					}
					else if (shape.getPosition().x + VELOCITY > window.getSize().x - shape.getSize().x) {
						shape.setPosition(window.getSize().x - shape.getSize().x, shape.getPosition().y);
					}
				}
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}