#include "Wall.hpp"

namespace pg {

	Wall::Wall() : GameObject() {
		_initProperties();
	}

	void Wall::_initProperties() {
		std::cout << "ASDF ";
		m_isMovable = false;
		m_isObstacle = true;
	}

	Wall::~Wall() {

	}

}; // namespace gp
