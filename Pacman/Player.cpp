#include "Player.hpp"

namespace pg {

	Player::Player() {

	}

	void Player::update() {
		if (!m_actor) return;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			m_actor->goLeft();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			m_actor->goTop();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			m_actor->goRight();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			m_actor->goBottom();
		}
	}

	void Player::setActor(Actor *actor) {
		m_actor = actor;
	}

	Actor* Player::getActor() {
		return m_actor;
	}

	Player::~Player() {

	}

} // namespace pg