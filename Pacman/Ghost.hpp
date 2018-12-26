#pragma once

#include "Actor.hpp"
#include "Pacman.hpp"

namespace pg {

	class Ghost : public Actor {
	public:
		Ghost();
		~Ghost();

		void updateAnimation(int frameTime) override;
		void interact(pg::GameObject *obj) override;

	protected:
		void go(int frameTime) override;

	private:
		
	};

}; // namespace pg