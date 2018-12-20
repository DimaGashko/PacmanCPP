#pragma once

#include "GameField.hpp"
#include "Player.hpp"
#include "GameInfo.hpp"
#include "Menu.hpp"

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

