#pragma once

#include <SFML/Graphics.hpp>

namespace pg {

	class Animation	{

	public:
		Animation(sf::RectangleShape *rect, sf::Texture &texture);
		~Animation();

	private:

		sf::RectangleShape *m_rect;
		sf::Texture m_texture;

	};

}

