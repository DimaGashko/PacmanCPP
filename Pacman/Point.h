#pragma once

#include "Bonus.h"
#include "Pacman.h"

class Point : public Bonus {
public:
	Point();
	void addScore(Pacman pacman);
	~Point();
};

