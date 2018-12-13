#pragma once

class GameField {
public:
	GameField();
	void create();
	void update();
	void render();
	void checkCollision();
	~GameField();
};

