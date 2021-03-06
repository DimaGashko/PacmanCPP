#include "Actor.hpp"

namespace pg {

	Actor::Actor() : 
		GObject(),
		m_step(0.1f)
	{
		m_isMovable = true;
		m_isObstacle = false;
	}

	void Actor::interact(pg::GObject *obj) {

	}

	void Actor::updateSpeed(int frameTime) {
		auto step = m_step * frameTime;
		sf::Vector2f dir;

		if (m_goingLeft) dir.x = -step;
		if (m_goingTop) dir.y = -step;
		if (m_goingRight) dir.x = step;
		if (m_goingBottom) dir.y = step;

		addToSpeed(dir);

		m_goingLeft = false;
		m_goingTop = false;
		m_goingRight = false;
		m_goingBottom = false;
	}
	
	void Actor::updateAnimation(int frameTime) {
		if (m_animationManager == NULL) return;

		std::string curAnim = m_animationManager->getCurAnimName();
		std::string type;

		auto speed = getSpeed();

		if (speed.x < 0) type = "left";
		else if (speed.y < 0) type = "top";
		else if (speed.x > 0) type = "right";
		else if (speed.y > 0) type = "bottom";

		else {			
			if (curAnim == "left") type = "stayLeft";
			else if (curAnim == "top") type = "stayTop";
			else if (curAnim == "right") type = "stayRight";
			else if (curAnim == "bottom") type = "stayBottom";
		}

		if (type.size() != 0) {
			m_animationManager->set(type);
		} 
	}

	void Actor::setStartAnim() {
		if (m_animationManager == NULL) return;

		m_animationManager->set("right");
	}

	void Actor::goLeft() {
		m_goingLeft = true;
	}

	void Actor::goRight() {
		m_goingRight = true;
	}

	void Actor::goTop() {
		m_goingTop = true;
	}

	void Actor::goBottom() {
		m_goingBottom = true;
	}

	Actor::~Actor() {

	}

}; // namespace pg