#pragma once

#include <SFML/Graphics.hpp>

#include "Bonus.hpp"

namespace pg {

	class Point : public Bonus {
	public:
		Point();
		Point(sf::Texture *texture);
		~Point();

	private:
		
	};

}