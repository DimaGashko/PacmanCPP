#include "Wall.hpp"

namespace pg {

	Wall::Wall() : GObject() {
		m_isMovable = false;
		m_isObstacle = true;
	}

	void Wall::updateAnimation(int frameTime) {
		if (m_animationManager == NULL) return;

	}

	void Wall::setStartAnim() {

	}

	void Wall::interact(pg::GObject *obj) {
	
	}

	void Wall::updateSpeed(int frameTime) {
	
	}

	Wall::~Wall() {

	}

}; // namespace gp
