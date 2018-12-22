#pragma once

#include <SFML/Graphics.hpp>

#include "Camera.hpp"
#include "GameField.hpp"

#include "GameObject.hpp"
#include "LevelLoader.hpp"
#include "Player.hpp"

namespace pg {

	class PacmanGame {
	public:
		PacmanGame();

		void run();

		~PacmanGame();

	private:
		struct _gameStates {
			bool pause = false;
		};

		_gameStates m_gameStates;

		GameField *m_gameField;
		LevelLoader m_levelLoader;

		Player m_player;
		Camera m_carera;
		
		sf::RenderWindow m_window;

		int m_frameTime = 0;

		void update();
		void _updateGameField();

		void draw();
		void _drawGameField();

		void _createGame();
		void _initWindow();
		
	};

}; // namespace pg