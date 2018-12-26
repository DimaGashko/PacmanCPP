#include "Ghost.hpp"

namespace pg {

	Ghost::Ghost() : Actor() {

	}

	void Ghost::updateAnimation(int frameTime) {
		if (m_animationManager == NULL) return;
	
		Actor::updateAnimation(frameTime);
		//m_animationManager->set("right");
	}
	
	Ghost::~Ghost() {

	}

}; //namespace pg
