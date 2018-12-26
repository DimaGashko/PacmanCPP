#include "Actor.hpp"

namespace pg {

	Actor::Actor() : GameObject() {
		m_isMovable = true;
		m_isObstacle = false;
	}

	void Actor::goLeft() {
		m_goingLeft = true;
	}

	void Actor::goRight() {
		m_goingRight = true;
	}

	void Actor::goTop() {
		m_goingTop = true;
	}

	void Actor::goBottom() {
		m_goingBottom = true;
	}

	Actor::~Actor() {

	}

}; // namespace pg