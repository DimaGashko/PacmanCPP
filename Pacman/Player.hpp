#pragma once

#include <SFML/Graphics.hpp>

#include "Actor.hpp"

namespace pg {

	class Player {
	public:
		Player();

		void update(int frameTime);

		void setActor(Actor *actor);
		Actor *getActor();

		~Player();

	private:
		Actor *m_actor;
	};

} // namespace pg

