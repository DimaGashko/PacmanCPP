#include "Player.hpp"

namespace pg {

	Player::Player() {

	}

	void Player::update(int frameTime) {
		if (!m_actor) return;

		int step = 0.2 * frameTime;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			m_actor->move(sf::Vector2f(-step, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			m_actor->move(sf::Vector2f(0, -step));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			m_actor->move(sf::Vector2f(step, 0));
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			m_actor->move(sf::Vector2f(0, step));
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