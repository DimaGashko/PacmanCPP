#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "lib/tinyxml2.h"
#include "PacmanGame.hpp"

using namespace std;
using namespace tinyxml2;

int main() {
	//system("pause");

	{
		pg::PacmanGame pacmanGame;
		pacmanGame.run();
	}

	//system("pause");
	return 0;
}
