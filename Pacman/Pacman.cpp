#include "Pacman.hpp"

namespace pg {

	Pacman::Pacman() : Actor() {

	}

	void Pacman::updateAnimation(int frameTime) {
		if (m_animationManager == NULL) return;
		Actor::updateAnimation(frameTime);

		m_animationManager->update(frameTime);
	}

	Pacman::~Pacman() {

	}

}