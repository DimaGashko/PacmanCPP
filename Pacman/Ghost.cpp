#include "Ghost.hpp"

namespace pg {

	Ghost::Ghost() : Actor() {

	}

	void Ghost::updateAnimation(int frameTime) {
		if (m_animationManager == NULL) return;
	
		Actor::updateAnimation(frameTime);
	}

	void Ghost::updateSpeed(int frameTime) {
		m_stepsRest--;

		auto step = m_step * frameTime;
		auto pos = getPosition();

		if (m_stepsRest <= 0 ) {
			float k = float(rand()) / RAND_MAX;

			if (k < 0.25) m_dir = "left";
			else if (k < 0.5) m_dir = "top";
			else if (k < 0.75) m_dir = "right";
			else if (k < 1) m_dir = "bottom";

			m_stepsRest = rand() % 1000;

			m_goingLeft = (m_dir == "left");
			m_goingTop = (m_dir == "top");
			m_goingRight = (m_dir == "right");
			m_goingBottom = (m_dir == "bottom");
		}

		sf::Vector2f dir;

		if (m_dir == "left") dir.x = -step;
		if (m_dir == "top") dir.y = -step;
		if (m_dir == "right") dir.x = step;
		if (m_dir == "bottom") dir.y = step;

		addToSpeed(dir);
	}

	void Ghost::interact(pg::GObject *obj) {
		if (dynamic_cast<Pacman*>(obj) != nullptr) {
			obj->die();
		}
	}
	
	Ghost::~Ghost() {

	}

}; //namespace pg
