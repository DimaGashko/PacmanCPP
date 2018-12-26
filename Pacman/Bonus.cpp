#include "Bonus.hpp"

namespace pg {

	Bonus::Bonus() : GameObject() {
		m_isMovable = false;
		m_isObstacle = false;
	}

	void Bonus::updateAnimation(int frameTime) {
		if (m_animationManager == NULL) return;
	}

	void Bonus::setStartAnim() {

	}

	void Bonus::interact(pg::GameObject *obj) {
		use(obj);
	}

	Bonus::~Bonus() {

	}

} // namespace pg