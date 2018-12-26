#include "Actor.hpp"

namespace pg {

	Actor::Actor() : 
		GameObject(),
		m_step(0.1f)
	{
		m_isMovable = true;
		m_isObstacle = false;
	}

	void Actor::update(int frameTime) {
		GameObject::update(frameTime);

		go(frameTime);
	}

	void Actor::go(int frameTime) {
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
		m_animationManager->set("right");

		/*if (m_goingLeft) m_animationManager->set("left");
		else if (m_goingRight) m_animationManager->set("right");
		else if (m_goingTop) m_animationManager->set("top");
		else if (m_goingBottom) m_animationManager->set("bottom");
		m_animationManager->set("stay");*/
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