#include "Actor.hpp"

namespace pg {

	Actor::Actor() : GameObject() {
		_initProperties();
	}

	Actor::Actor(sf::Texture *texture) : GameObject(texture) {
		_initProperties();
	}

	void Actor::_initProperties() {
		m_isMovable = true;
		m_isObstacle = false;
	}


	Actor::~Actor() {

	}

}; // namespace pg