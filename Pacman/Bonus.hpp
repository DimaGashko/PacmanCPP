#pragma once

#include "StaticObject.hpp"
#include "Actor.hpp"

class Bonus : public StaticObject {
public:
	Bonus();
	void use(Actor actor);
	~Bonus();
};

