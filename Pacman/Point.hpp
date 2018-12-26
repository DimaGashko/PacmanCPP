#pragma once

#include <SFML/Graphics.hpp>

#include "Bonus.hpp"

namespace pg {

	class Point : public Bonus {
	public:
		Point();

		void use(pg::GameObject *obj) override;

		~Point();

	private:
		
	};

}