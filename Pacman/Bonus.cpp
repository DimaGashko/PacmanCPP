#include "Bonus.hpp"

namespace pg {

	Bonus::Bonus() : GObject() {
		m_isMovable = false;
		m_isObstacle = false;
	}

	void Bonus::updateAnimation(int frameTime) {
		if (m_animationManager == NULL) return;
	}

	void Bonus::setStartAnim() {

	}

	void Bonus::interact(pg::GObject *obj) {
		use(obj);
	}

	void Bonus::updateSpeed(int frameTime) {
	
	}

	Bonus::~Bonus() {

	}

} // namespace pg