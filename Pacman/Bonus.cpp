#include "Bonus.hpp"

namespace pg {

	Bonus::Bonus() : GameObject() {

	}

	Bonus::Bonus(sf::Texture *texture) : GameObject(texture) {

	}

	void Bonus::_initProperties() {
		m_isMovable = false;
		m_isObstacle = false;
	}


	Bonus::~Bonus() {

	}

} // namespace pg