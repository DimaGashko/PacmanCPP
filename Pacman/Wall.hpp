#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

namespace pg {

	class Wall : public GameObject {
	public:
		Wall();
		Wall(sf::Texture *texture);

		~Wall();

	private:

		void _initProperties() override;
	};

}; // namespace pg

