#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace pg {

	class GameObject {
	public:
		GameObject();
		void draw(sf::RenderTarget &window);
		GameObject(sf::Texture *texture);
		sf::Vector2f getPosition();
		void setPosition(sf::Vector2f coords);
		void setSize(sf::Vector2f size);
		~GameObject();
	private:
		sf::RectangleShape m_rect;

		bool m_isBarrier = false;

		void init();
	};

}; // namespace pg