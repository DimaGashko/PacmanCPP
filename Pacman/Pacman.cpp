#include "Pacman.hpp"

namespace pg {

	Pacman::Pacman() : Actor() {

	}

	void Pacman::updateAnimation(int frameTime) {
		if (m_animationManager == NULL) return;
		Actor::updateAnimation(frameTime);

	}

	void Pacman::interact(pg::GObject *obj) {
		Actor::interact(obj);

		if (dynamic_cast<Point*>(obj) != nullptr) {
			onPointEat();
		}
	}

	void Pacman::onPointEat() {
		m_sounds.playOnce("sounds/eatfruit.wav");
	}

	Pacman::~Pacman() {

	}

}