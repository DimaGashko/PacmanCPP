#include "Wall.hpp"

namespace pg {

	Wall::Wall() : GameObject() {
	
	}

	Wall::Wall(sf::Texture *texture) : GameObject(texture) {

	}

	void Wall::_initProperties() {
		m_isMovable = false;
		m_isObstacle = true;
	}

	Wall::~Wall() {

	}

}; // namespace gp
