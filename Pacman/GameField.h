#pragma once
class GameField
{
public:
	GameField();
	void build();
	void update();
	void render();
	void checkCollision();
	~GameField();
};

