#include <iostream>
#include <SFML/Graphics.hpp>

#include "PacmanGame.hpp"

using namespace std;

int main() {
	pg::PacmanGame pacmanGame;
	pacmanGame.run();

	sf::View view(sf::IntRect());


	return 0;
}
