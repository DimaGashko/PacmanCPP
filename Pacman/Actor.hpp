#pragma once

#include "DinamicObject.hpp"

class Actor : public DinamicObject {
public:
	Actor();
	void eat(Actor food);
	~Actor();

private:
	int _power;
};

