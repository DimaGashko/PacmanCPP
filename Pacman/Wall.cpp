#include "Wall.hpp"

namespace pg {

	Wall::Wall() : GameObject() {
		m_isMovable = false;
		m_isObstacle = true;
	}

	void Wall::updateAnimation(int frameTime) {
		if (m_animationManager == NULL) return;

	}

	void Wall::setStartAnim() {

	}

	Wall::~Wall() {

	}

}; // namespace gp
