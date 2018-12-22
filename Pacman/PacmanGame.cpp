#include "PacmanGame.hpp"

namespace pg {

	PacmanGame::PacmanGame() : m_camera(&m_window) {		
		_initWindow();
	}

	void PacmanGame::_initWindow() {
		sf::ContextSettings settings;
		settings.antialiasingLevel = 0;

		m_window.create(sf::VideoMode(1000, 600), "Pacman", sf::Style::Default , settings);
		m_window.setFramerateLimit(120);

		m_camera.init();
	}

	void PacmanGame::run() {
		_createGame();

		sf::Clock clock;

		while (m_window.isOpen()) {
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

			m_window.clear();

			update();
			draw();

			m_window.display();
		}
	}

	void PacmanGame::update() {
		_updateGameField();
	}

	void PacmanGame::draw() {
		_drawGameField();
		
	}

	void PacmanGame::_drawGameField() {
		auto visibleObjects = m_gameField->getObjectsOfRange(
			m_window.mapPixelToCoords(sf::Vector2i(-100, -100)),
			m_window.mapPixelToCoords(sf::Vector2i(m_window.getSize()))
		);

		m_gameField->draw(m_window, visibleObjects);

		if (m_player.getActor()) {
			m_player.getActor()->draw(m_window);
		}
	}

	void PacmanGame::_updateGameField() {
		m_player.update(m_frameTime);
		m_camera.update();

		m_gameField->update(sf::Vector2f(m_window.getSize()), m_frameTime);
	}

	void PacmanGame::_createGame() {
		auto level = m_levelLoader.loadFromTmx("configs/levels/level1.tmx");

		m_gameField = level.gameField;

		m_player.setActor(level.player);
		m_camera.setTarget(level.player);
	}

	PacmanGame::~PacmanGame() {
		delete m_gameField;
	}

} // namespace pg


