#include "Bonus.hpp"

namespace pg {

	Bonus::Bonus() : GameObject() {
		m_isMovable = false;
		m_isObstacle = false;
	}

	void Bonus::updateAnimation(int frameTime) {
		if (m_animationManager == NULL) return;
	}

	Bonus::~Bonus() {

	}

} // namespace pg