#pragma once

#include "Bonus.h"
#include "Actor.h"

class Point : public Bonus {
public:
	Point();
	void addScore(Actor pacman);
	~Point();
};

