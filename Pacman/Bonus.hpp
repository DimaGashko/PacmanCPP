#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

namespace pg {

	class Bonus : public GameObject {
	public:

		Bonus();

		void updateAnimation(int frameTime) override;
		void setStartAnim() override;
		void interact(pg::GameObject *obj);

		virtual void use(pg::GameObject *obj) = 0;

		~Bonus();

	private:
		
	};

}