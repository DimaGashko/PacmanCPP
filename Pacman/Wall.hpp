#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

namespace pg {

	class Wall : public GameObject {
	public:
		Wall();

		void updateAnimation(int frameTime) override;
		void setStartAnim() override;

		~Wall();

	private:

	};

}; // namespace pg

