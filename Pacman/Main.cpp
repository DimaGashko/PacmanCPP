#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "lib/tinyxml2.h"
#include "PacmanGame.hpp"

using namespace std;
using namespace tinyxml2;

int main() {
	XMLDocument level;
	auto err = level.LoadFile("configs/levels/level1.tmx");

	if (err != XMLError::XML_SUCCESS) {
		cout << "Error load";
		system("pause");
		return 0;
	}

	auto map = level.FirstChildElement("map")->FirstChildElement("layer")->FirstChildElement("data");
	level.FirstChildElement("map").
	cout << map->GetText() << endl;


	system("pause");
	pg::PacmanGame pacmanGame;
	pacmanGame.run();

	sf::View view(sf::IntRect());


	return 0;
}
