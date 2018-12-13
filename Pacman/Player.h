#pragma once

#include "Actor.h"

class Player {
public:
	Player();
	void moveActor(float x, float y);
	int getScore();
	int addScore(int val);
	void setTarg(Actor &actor); 
	Actor& getTarg();
	~Player();
};

