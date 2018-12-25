#include "Actor.hpp"

namespace pg {

	Actor::Actor() : GameObject() {

	}

	Actor::Actor(sf::Texture *texture) : GameObject(texture) {

	}

	void Actor::_initProperties() {
		m_isMovable = true;
		m_isObstacle = false;
	}


	Actor::~Actor() {

	}

}; // namespace pg