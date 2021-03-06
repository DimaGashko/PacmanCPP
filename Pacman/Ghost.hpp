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
		void interact(pg::GObject *obj) override;

	protected:
		float m_step;

	private:
		std::string m_dir;
		int m_stepsRest;
		bool m_wasInteract;
		
	};

}; // namespace pg