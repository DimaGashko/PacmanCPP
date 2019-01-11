#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "SoundManager.hpp"
#include "Camera.hpp"
#include "GField.hpp"

#include "GObject.hpp"
#include "LevelLoader.hpp"
#include "Player.hpp" 

namespace pg {

	class PacmanGame {
	public: 
		PacmanGame();

		void run();

		~PacmanGame();

	private:
		GField *m_gameField;
		LevelLoader m_levelLoader;

		Player m_player;
		Camera m_camera;

		SoundManager soundsManager;
		
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

		void _playBgSound();
		
		sf::Vector2f _getGameSize();

		sf::FloatRect _getVisibleRange();
	};

}; // namespace pg