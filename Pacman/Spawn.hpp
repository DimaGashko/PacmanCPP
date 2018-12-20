#pragma once

#include "StaticObject.hpp"
#include "Ghost.hpp"

class Spawn : public StaticObject {
public:
	Spawn();
	Ghost& generateGhost();
	~Spawn();
};

