#include "PacmanGame.hpp"

namespace pg {

	PacmanGame::PacmanGame() {
		_initWindow();
	}

	void PacmanGame::_initWindow() {
		sf::ContextSettings settings;
		settings.antialiasingLevel = 0;

		m_window.create(sf::VideoMode(1000, 600), "Figure", sf::Style::Default, settings);
		m_window.setFramerateLimit(180);

		m_window.setView(m_view);
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
					sf::Vector2f center(event.size.width / 2.f, event.size.height/ 2.f);

					m_view.setCenter(center);
					m_view.setSize(center);
				}
			}

			m_window.clear();

			update();
			render();
			
			m_window.display();
		}
	}

	void PacmanGame::update() {
		
	}

	void PacmanGame::render() {
		sf::RectangleShape rect(sf::Vector2f(16, 16));
		rect.setPosition(sf::Vector2f(-8, -8));
			
		m_window.draw(rect);
	}

	PacmanGame::~PacmanGame() {

	}

} // namespace pg