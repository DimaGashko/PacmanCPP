#include <SFML/Graphics.hpp>

#include "Actor.hpp"

namespace pg {

	Actor::Actor() : GameObject() {

	}

	Actor::Actor(sf::Texture *texture) : GameObject(texture) {

	}


	Actor::~Actor() {

	}

} // namespace pg