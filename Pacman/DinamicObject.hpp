#pragma once

#include "StaticObject.h"

class DinamicObject : public StaticObject {
public:
	DinamicObject();
	void interact();
	void move(float x, float y);
	~DinamicObject();
};

