#pragma once

#include "StaticObject.hpp"

class DinamicObject : public StaticObject {
public:
	DinamicObject();
	void interact();
	void move(float x, float y);
	~DinamicObject();
};

