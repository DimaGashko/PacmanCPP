#include "PacmanGame.hpp"

namespace pg {

	PacmanGame::PacmanGame() : m_camera(&m_window) {		
		_initWindow();
		_initLevels();
	}

	void PacmanGame::_initWindow() {
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;

		m_window.create(sf::VideoMode(750, 650), "Pacman", sf::Style::Default , settings);
		//m_window.setFramerateLimit(120);

		m_camera.init();	
	}

	void PacmanGame::run() {
		openNextLevel();

		sf::Clock clock;

		while (m_window.isOpen()) {
			//std::cout << 1000 / (m_frameTime + 0.01) << std::endl;
			m_frameTime = clock.restart().asMilliseconds();

			sf::Event event;
			while (m_window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					m_window.close();
				}
				else if (event.type == sf::Event::Resized) {
					m_camera.updateSize();
				}
			}

			if (m_window.hasFocus()) {
				m_window.clear();
				update();
				draw();
				m_window.display();
			}

		}
	}

	void PacmanGame::update() {
		_updateGameField();
	
	}

	void PacmanGame::draw() {
		_drawGameField();
	}

	void PacmanGame::openNextLevel() {
		m_currentLevel += 1;

		if (m_currentLevel > (int)m_levels.size()) {
			m_currentLevel = (int)m_levels.size();
		}

		if (m_levels.size() <= m_currentLevel) {
			gameWon();
			return;
		}

		_loadLevel(m_levels[m_currentLevel]);
	}

	void PacmanGame::gameWon() {
		std::cout << "You won the game \n";
	}

	void PacmanGame::_updateGameField() {
		m_player.update();
		m_gameField->update(_getGameSize(), m_frameTime);

		m_camera.update();
	
		if (m_gameField->checkWon()) {
			std::cout << "You won the level \n"
				<< (m_currentLevel + 1) << std::endl;

			openNextLevel();
		}

		if (m_gameField->checkGameOver()) {
			std::cout << "Game Over \n"
				<< (m_currentLevel + 1) << std::endl;

			m_currentLevel -= 1;
			openNextLevel();
		}
	}

	void PacmanGame::_drawGameField() {
		m_gameField->draw(m_window, _getVisibleRange());

		if (m_player.getActor()) {
			m_player.getActor()->draw(m_window);
		}
	}

	void PacmanGame::_loadLevel(std::string url) {
		m_gameField = m_levelLoader.loadFromTmx(url);
		m_player.setActor(m_gameField->getPlayer());
		m_camera.setTarget(m_player.getActor());

		if (m_player.getActor() == NULL) throw "Player is NULL";
	}

	sf::FloatRect PacmanGame::_getVisibleRange() {
		sf::Vector2f start = m_window.mapPixelToCoords(sf::Vector2i(-50, -50));

		sf::Vector2f end = m_window.mapPixelToCoords(
			sf::Vector2i(m_window.getSize())
		);

		return sf::FloatRect(start, end - start + sf::Vector2f(20, 20));
	}

	sf::Vector2f PacmanGame::_getGameSize() {
		return sf::Vector2f(m_camera.getView().getSize());
	}

	void PacmanGame::_initLevels() {

		m_levels.push_back("configs/levels/level1.tmx");
		m_levels.push_back("configs/levels/level2.tmx");
		m_levels.push_back("configs/levels/level3.tmx");

	}

	PacmanGame::~PacmanGame() {
		delete m_gameField;
	}

}; // namespace pg


