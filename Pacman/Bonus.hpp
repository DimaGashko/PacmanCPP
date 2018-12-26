#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

namespace pg {

	class Bonus : public GameObject {
	public:

		Bonus();

		void updateAnimation(int frameTime) override;
		void setStartAnim() override;

		~Bonus();

	private:
		
	};

}