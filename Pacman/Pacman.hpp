#pragma once

#include "Actor.hpp"

class Pacman :	public Actor {
public:
	Pacman();
	int getScore();
	int addScore(int val);
	~Pacman();

private:
	int _score;
};

