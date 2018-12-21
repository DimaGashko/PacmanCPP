#pragma once

#include <SFML/Graphics.hpp>

#include "GameField.hpp"

namespace pg {

	class PacmanGame {
	public:
		PacmanGame();
		void run();

		~PacmanGame();

	private:
		GameField *m_gameField;
		
		sf::RenderWindow m_window;
		sf::View m_view;

		int m_frameTime = 0;

		void update();
		void render();

		void _updateView();

		void _initWindow();
		
	};

}; // namespace pg