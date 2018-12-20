#pragma once

#include "Bonus.hpp"
#include "Actor.hpp"

class Point : public Bonus {
public:
	Point();
	void addScore(Actor pacman);
	~Point();
};

