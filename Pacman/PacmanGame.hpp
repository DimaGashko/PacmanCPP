#pragma once

#include <SFML/Graphics.hpp>

namespace pg {

	class PacmanGame {
	public:
		PacmanGame();
		void run();

		~PacmanGame();

	private:
		sf::RenderWindow m_window;
		sf::View m_view;

		int m_frameTime = 0;

		void update();
		void render();

		void _initWindow();
		
	};

}; // namespace pg