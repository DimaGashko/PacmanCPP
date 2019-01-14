#pragma once

#include <SFML/Graphics.hpp>

#include "Actor.hpp"
#include "Point.hpp"

namespace pg {

	class Pacman : public Actor {
	public:
		Pacman();

		void updateAnimation(int frameTime) override;
		void interact(pg::GObject *obj) override;

		~Pacman();

	private:

		void onPointEat();
		
	};

} // namespace pg
