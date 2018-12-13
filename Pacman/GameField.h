#pragma once

#include <vector>
#include "StaticObject.h"

class GameField {
public:
	GameField();
	void create();
	void update();
	void render();
	void checkCollision();
	~GameField();
private: 
	std::vector<std::vector<int>> _objects;
};

