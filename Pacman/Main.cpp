#include <iostream>
#include <string>

#include "PacmanGame.hpp"
#include "Wall.hpp"
#include "Singleton.hpp"

using namespace std;

int main() {
	srand((int)time(0));

	pg::Wall *wall = pg::Singleton<pg::Wall>::getInstance();

	pg::Wall *wall2 = pg::Singleton<pg::Wall>::getInstance();

	wall2->setLeft(111);
	cout << wall->getLeft() << endl;

	wall->setTop(222);
	cout << wall2->getTop() << endl;

	system("pause");

	//system("pause");

	{
		pg::PacmanGame pacmanGame;
		pacmanGame.run();
	}

	//system("pause");
	return 0;
}
