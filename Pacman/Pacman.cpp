#include "Pacman.hpp"

namespace pg {

	Pacman::Pacman() : Actor() {

	}

	Pacman::Pacman(sf::Texture *texture) : Actor(texture) {

	}

	sf::FloatRect Pacman::getBounds() {
		auto pos = getPosition();
		auto size = getSize();

		return sf::FloatRect(pos.x+1, pos.y+1, size.x-2, size.y-2);
	}


	Pacman::~Pacman() {
	}

}