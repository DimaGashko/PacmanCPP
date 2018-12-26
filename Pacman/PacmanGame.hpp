#pragma once

#include <string>

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
		GameField *m_gameField;
		LevelLoader m_levelLoader;

		Player m_player;
		Camera m_camera;
		
		sf::RenderWindow m_window;

		int m_frameTime = 0;

		int m_currentLevel = -1;
		std::vector<std::string> m_levels;

		void update();
		void draw();

		void openNextLevel();

		void gameWon();

		void _updateGameField();
		void _drawGameField();

		void _loadLevel(std::string url);

		void _initWindow();
		void _initLevels();
		
		sf::Vector2f _getGameSize();

		sf::FloatRect _getVisibleRange();
	};

}; // namespace pg