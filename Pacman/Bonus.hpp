#pragma once

#include "StaticObject.h"
#include "Actor.h"

class Bonus : public StaticObject {
public:
	Bonus();
	void use(Actor actor);
	~Bonus();
};

