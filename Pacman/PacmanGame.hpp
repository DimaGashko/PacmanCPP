#pragma once

#include <SFML/Graphics.hpp>

#include "GameField.hpp"
#include "GameObject.hpp"
#include "LevelLoader.hpp"

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
		
		sf::RenderWindow m_window;
		sf::View m_view;

		int m_frameTime = 0;

		void update();
		void render();

		void _createGame();
		void _updateView();
		void _positionView();
		void _initWindow();
		
	};

}; // namespace pg