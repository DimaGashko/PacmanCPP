#include "PacmanGame.hpp"

namespace pg {

	PacmanGame::PacmanGame() : m_camera(&m_window) {		
		_initWindow();
	}

	void PacmanGame::_initWindow() {
		sf::ContextSettings settings;
		settings.antialiasingLevel = 0;

		m_window.create(sf::VideoMode(800, 650), "Pacman", sf::Style::Default , settings);
		//m_window.setFramerateLimit(120);

		m_camera.init();
		
	}

	void PacmanGame::run() {
		_createGame();

		sf::Clock clock;

		while (m_window.isOpen()) {
			std::cout << 1000 / (m_frameTime + 0.01) << std::endl;
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


			if (m_window.hasFocus() || 1) {
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

	void PacmanGame::_updateGameField() {
		m_player.update(m_frameTime);
		m_gameField->update(sf::Vector2f(m_window.getSize()), m_frameTime);

		m_camera.update();
	}

	void PacmanGame::_drawGameField() {
		m_gameField->draw(m_window, _getVisibleRange());

		if (m_player.getActor()) {
			m_player.getActor()->draw(m_window);
		}
	}

	void PacmanGame::_createGame() {
		m_gameField = m_levelLoader.loadFromTmx("configs/levels/level2.tmx");
		m_player.setActor(m_gameField->getPlayer());
		m_camera.setTarget(m_player.getActor());
	}

	sf::FloatRect PacmanGame::_getVisibleRange() {
		sf::Vector2f start = m_window.mapPixelToCoords(sf::Vector2i(-50, -50));
		sf::Vector2f end = m_window.mapPixelToCoords(sf::Vector2i(m_window.getSize()));

		return sf::FloatRect(start, end - start);
	}

	PacmanGame::~PacmanGame() {
		delete m_gameField;
	}

} // namespace pg


