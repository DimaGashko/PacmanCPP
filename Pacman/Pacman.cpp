#include "Pacman.hpp"

namespace pg {

	Pacman::Pacman() : Actor() {

	}

	void Pacman::updateAnimation(int frameTime) {
		if (m_animationManager == NULL) return;

		m_animationManager->set("right");

		m_animationManager->update(frameTime);
	}

	Pacman::~Pacman() {

	}

}