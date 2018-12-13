#pragma once

#include "DinamicObject.h"

class Actor : public DinamicObject {
public:
	Actor();
	void eat(Actor food);
	~Actor();

private:
	int _power;
};

