#pragma once

#include "GameObject.hpp"

namespace pg {

	class Wall : public GameObject {
	public:
		Wall();
		Wall(sf::Texture texture);
		~Wall();

	private:

	};

}; // namespace pg

