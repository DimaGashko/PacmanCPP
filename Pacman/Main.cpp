#include <iostream>
#include <string>

#include "PacmanGame.hpp"
#include "Wall.hpp"
#include "Singleton.hpp"

using namespace std;

int main() {
	srand((int)time(0));

	pg::Wall wall = pg::Singleton<pg::Wall>::getInstance();

	cout << wall.getPosition().x << endl;

	system("pause");

	//system("pause");

	{
		pg::PacmanGame pacmanGame;
		pacmanGame.run();
	}

	//system("pause");
	return 0;
}
