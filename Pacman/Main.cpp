#include <iostream>

#include <SFML/Graphics.hpp>

#include "PacmanGame.hpp"
#include "GameObject.hpp"

using namespace std;

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	sf::RenderWindow window(sf::VideoMode(1000, 600), "Figure", sf::Style::Default, settings);
	window.setFramerateLimit(180);

	sf::Clock clock;
	int frameTime;

	pg::GameObject obj;

	while (window.isOpen()) {
		frameTime = clock.restart().asMilliseconds();

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::Resized) {
				sf::FloatRect visible(0, 0, float(event.size.width), float(event.size.height));
				window.setView(sf::View(visible));
			}
		}

		window.clear();
		obj.draw(window);
		window.display();
	}

	//pg::PacmanGame pacmanGame;
	//pacmanGame.run();

	return 0;
}
