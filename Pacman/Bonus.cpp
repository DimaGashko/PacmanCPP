#include "Bonus.hpp"

namespace pg {

	Bonus::Bonus() : GameObject() {
		_initProperties();
	}

	Bonus::Bonus(sf::Texture *texture) : GameObject(texture) {
		_initProperties();
	}

	void Bonus::_initProperties() {
		m_isMovable = false;
		m_isObstacle = false;
	}


	Bonus::~Bonus() {

	}

} // namespace pg