#pragma once

#include "Actor.h"

class Pacman :	public Actor {
public:
	Pacman();
	int getScore();
	int addScore(int val);
	~Pacman();

private:
	int _score;
};

