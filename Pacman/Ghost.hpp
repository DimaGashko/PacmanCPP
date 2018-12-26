#pragma once

#include "Actor.hpp"

namespace pg {

	class Ghost : public Actor {
	public:
		Ghost();

		void updateAnimation(int frameTime) override;

		~Ghost();
	};

}; // namespace pg