#pragma once

#include <SFML/Graphics.hpp>

#include "Actor.hpp"

namespace pg {

	class Pacman : public Actor {
	public:
		Pacman();

		void updateAnimation(int frameTime) override;

		~Pacman();

	private:
		
	};

} // namespace pg
