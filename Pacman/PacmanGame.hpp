#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "Singleton.hpp"
#include "FrameTimeManager.hpp"
#include "SoundBuffersManager.hpp"
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

		SoundManager m_sounds;
		FrameTimeManager m_frameTime;
		
		sf::RenderWindow m_window;

		int m_currentLevel = 1 - 2;
		std::vector<std::string> m_levels;

		sf::Music m_bgMusic;

		void update();
		void draw();

		void openNextLevel();

		void gameWon();

		void keyReleasedEvent();

		void _updateGameField();
		void _drawGameField();

		void _loadLevel(std::string url);

		void _initWindow();
		void _initLevels();
		
		sf::Vector2f _getGameSize();

		sf::FloatRect _getVisibleRange();
		
		void _playBgMusic();
	};

}; // namespace pg