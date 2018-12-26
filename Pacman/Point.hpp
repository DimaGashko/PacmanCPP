#pragma once

#include <SFML/Graphics.hpp>

#include "Bonus.hpp"
#include "Pacman.hpp"

namespace pg {

	class Point : public Bonus {
	public:
		Point();

		void use(pg::GameObject *obj) override;
		bool itCanUseTheBonus(pg::GameObject *obj) override;

		~Point();

	private:
		
	};

}