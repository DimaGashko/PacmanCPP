#include "PacmanGame.hpp"

namespace pg {

	PacmanGame::PacmanGame() :
		m_view(sf::Vector2f(0, 0), sf::Vector2f(0, 0))
	{
		m_gameField = new GameField(sf::Vector2f(100, 100), sf::Vector2f(16, 16));

		for (int i = 0; i < 20; i+=2) {
			for (int j = 0; j < 10; j+=2) {
				m_gameField->addObject(new GameObject(sf::Vector2f(16 * i, 16 * j)));
			}
		} 

		_initWindow();
	}

	void PacmanGame::_initWindow() {
		sf::ContextSettings settings;
		settings.antialiasingLevel = 0;

		m_window.create(sf::VideoMode(1000, 600), "Pacman", sf::Style::Default, settings);
		m_window.setFramerateLimit(180);
		
		_updateView();
	}

	void PacmanGame::run() {
		sf::Clock clock;

		while (m_window.isOpen()) {
			m_frameTime = clock.restart().asMilliseconds();

			sf::Event event;
			while (m_window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					m_window.close();
				}
				else if (event.type == sf::Event::Resized) {
					_updateView();
				}
			}

			m_window.clear();

			update();
			render();
			
			m_window.display();
		}
	}

	void PacmanGame::_updateView() {
		auto size = m_window.getSize();
		m_view.setSize(sf::Vector2f(size.x / 2.f, size.y / 2.f));

		m_window.setView(m_view);
	}

	void PacmanGame::update() {
		m_view.move(0.1 * m_frameTime, 0.1 * m_frameTime);
		
		_updateView();
	}

	void PacmanGame::render() {
		auto objects = m_gameField->getObjectsOfRange(
			sf::Vector2f(-500, -500), sf::Vector2f(500, 500)
		);

		for (auto obj : objects) {
			obj->draw(m_window);
		}
	}

	PacmanGame::~PacmanGame() {

	}

} // namespace pg