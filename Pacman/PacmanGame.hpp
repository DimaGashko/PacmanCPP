#pragma once

#include "GameField.h"
#include "Player.h"
#include "GameInfo.h"
#include "Menu.h"

class PacmanGame {
public:
	PacmanGame();
	void run();

	void start();
	void pause();
	void resume();
	void load();
	void update();
	void render();
	~PacmanGame();

private:
	GameField *_gameField;
	Player *_player;
	GameInfo *_gameInfo;
	Menu _menu;
};

