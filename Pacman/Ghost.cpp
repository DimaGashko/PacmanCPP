#include "Ghost.hpp"

namespace pg {

	Ghost::Ghost() : Actor() {

	}

	void Ghost::updateAnimation(int frameTime) {
		if (m_animationManager == NULL) return;
	
		m_animationManager->set("right");
	}

	void Ghost::go(int frameTime) {
		auto pos = getPosition();
		auto dPos = m_prevPosition - pos;

		float step = m_step * frameTime;
		float minDx = 0.01 * frameTime;

		if (abs(dPos.x) < minDx && abs(dPos.y) < minDx) {
			m_dir = rand() % 8000;
		}
		
		if (m_dir < 2000) addToSpeed(sf::Vector2f(-step, 0));
		else if (m_dir < 4000) addToSpeed(sf::Vector2f(0, -step));
		else if (m_dir < 6000) addToSpeed(sf::Vector2f(step, 0));
		else addToSpeed(sf::Vector2f(0, step));

		m_prevPosition = pos;
	}

	void Ghost::interact(pg::GameObject *obj) {
		if (dynamic_cast<Pacman*>(obj) != nullptr) {
			obj->die();
		}
	}
	
	Ghost::~Ghost() {

	}

}; //namespace pg
