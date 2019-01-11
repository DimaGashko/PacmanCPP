#include <iostream>
#include <string>

#include "PacmanGame.hpp"

using namespace std;

int main() {
	srand((int)time(0));

	//system("pause");

	{
		pg::PacmanGame pacmanGame;
		pacmanGame.run();
	}

	//system("pause");
	return 0;
}
