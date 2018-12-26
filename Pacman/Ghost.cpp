#include "Ghost.hpp"

namespace pg {

	Ghost::Ghost() : Actor() {

	}

	void Ghost::updateAnimation(int frameTime) {
		if (m_animationManager == NULL) return;
	
		m_animationManager->set("right");
	}

	void Ghost::go(int frameTime) {
		
	}

	void Ghost::interact(pg::GameObject *obj) {
		if (dynamic_cast<Pacman*>(obj) != nullptr) {
			obj->die();
		}
	}
	
	Ghost::~Ghost() {

	}

}; //namespace pg
