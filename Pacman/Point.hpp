#pragma once

#include <SFML/Graphics.hpp>

#include "Bonus.hpp"
#include "Pacman.hpp"

namespace pg {

	class Point : public Bonus {
	public:
		Point();

		void use(pg::GObject *obj) override;
		bool canItUseTheBonus(pg::GObject *obj) override;

		~Point();

	private:
		
	};

}