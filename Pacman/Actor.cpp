#include "Actor.hpp"

namespace pg {

	Actor::Actor() : GameObject() {
		m_isMovable = true;
		m_isObstacle = false;
	}

	Actor::~Actor() {

	}

}; // namespace pg