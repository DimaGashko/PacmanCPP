#pragma once

#include "Actor.hpp"
#include "Pacman.hpp"

namespace pg {

	class Ghost : public Actor {
	public:
		Ghost();
		~Ghost();

		void updateAnimation(int frameTime) override;
		void updateSpeed(int frameTime) override;
		void interact(pg::GameObject *obj) override;

	private:
		std::string m_dir;
		int m_stepsRest;
		
	};

}; // namespace pg