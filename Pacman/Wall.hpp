#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

namespace pg {

	class Wall : public GameObject {
	public:
		Wall();

		void updateAnimation(int frameTime) override;
		void updateSpeed(int frameTime) override;
		void setStartAnim() override;
		void interact(pg::GameObject *obj) override;

		~Wall();

	private:

	};

}; // namespace pg

