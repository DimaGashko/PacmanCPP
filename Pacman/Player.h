#pragma once

#include "Actor.h"

class Player {
public:
	Player();
	void moveActor(float x, float y);
	void setActor(Actor &actor); 
	Actor& getActor();
	~Player();

private:
	Actor *_actor;
};

