#include "Ghost.hpp"

namespace pg {

	Ghost::Ghost() : Actor(),
		m_step(0.11f)
	{

	}

	void Ghost::updateAnimation(int frameTime) {
		if (m_animationManager == NULL) return;
	
		Actor::updateAnimation(frameTime);
	}

	void Ghost::updateSpeed(int frameTime) {
		m_stepsRest--;

		auto step = m_step * frameTime;
		auto pos = getPosition();

		bool isEndCoords = pos.x - (int)pos.x < step * 2
			&& pos.y - (int)pos.y < step * 2;

		if ((m_stepsRest <= 0 && isEndCoords) || m_wasInteract) {
			m_wasInteract = false;

			float k = float(rand()) / RAND_MAX;

			if (k <= 0.27) m_dir = "left";
			else if (k <= 0.54) m_dir = "top";
			else if (k <= 0.75) m_dir = "right";
			else if (k <= 1) m_dir = "bottom";
			else m_dir = "left";

			m_stepsRest = rand() % 200 + 10;

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

		//std::cout << getSpeed().x << "|" << getSpeed().y << std::endl;
	}

	void Ghost::interact(pg::GObject *obj) {
		if (obj->isObstacle()) {
			m_wasInteract = true;
		}

		if (dynamic_cast<Pacman*>(obj) != nullptr) {
			obj->die();
		}
	}
	
	Ghost::~Ghost() {

	}

}; //namespace pg
