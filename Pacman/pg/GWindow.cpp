#include "GWindow.h"

namespace pg {

	GWindow::GWindow(): title("PacmanGame") {
		
	}

	void GWindow::init() {
		initWindow();
	}

	void GWindow::initWindow() {
		sf::VideoMode display = sf::VideoMode::getDesktopMode();

		window.create(
			sf::VideoMode(display.width, display.height),
			title/*, sf::Style::Fullscreen*/
		);

		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();

			window.display();
		}
	}


	GWindow::~GWindow() {

	}

}