#pragma once

#include "StaticObject.h"
#include "Ghost.h"

class Spawn : public StaticObject {
public:
	Spawn();
	Ghost generateGhost();
	~Spawn();
};

