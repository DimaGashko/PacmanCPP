#pragma once

#include <SFML/Graphics.hpp>

#include "Actor.hpp"

namespace pg {

	class Pacman : public Actor {
	public:
		Pacman();
		Pacman(sf::Texture *texture);

		sf::FloatRect getBounds();

		~Pacman();

	private:
		
	};

} // namespace pg
