#include "Wall.hpp"

namespace pg {

	Wall::Wall() : GameObject() {
		_initProperties();
	}

	Wall::Wall(sf::Texture *texture) : GameObject(texture) {
		_initProperties();
	}

	void Wall::_initProperties() {
		m_isMovable = false;
		m_isObstacle = true;
	}

	Wall::~Wall() {

	}

}; // namespace gp
