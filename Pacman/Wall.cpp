#include "Wall.hpp"

namespace pg {

	Wall::Wall() : GameObject() {
		m_isMovable = false;
		m_isObstacle = true;
	}

	Wall::~Wall() {

	}

}; // namespace gp
