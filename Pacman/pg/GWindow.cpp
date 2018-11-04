#include "GWindow.h"

namespace pg {

	GWindow::GWindow(): title("PacmanGame") {
		
	}

	void GWindow::init() {
		initWindow();
	}

	void GWindow::initWindow() {
		window.create(sf::VideoMode::getFullscreenModes()[0], title/*, sf::Style::Fullscreen*/);
		window.setPosition(sf::Vector2i(0, 0));
		window.setFramerateLimit(maxFps);

		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			draw();
			window.display();
		}
	}

	void GWindow::draw() {
		
	}


	GWindow::~GWindow() {

	}

}