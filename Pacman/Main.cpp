#include <SFML/Graphics.hpp>

#include "pg/PacmanGame.h"

int main() {
	pg::PacmanGame pacmanGame;

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Blue);
	
	sf::Vector2f v1;

	sf::Vector3f v2;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}