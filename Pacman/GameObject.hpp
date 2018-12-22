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
		void move(sf::Vector2f offset);
		void setSize(sf::Vector2f size);
		sf::Vector2f getSize();
		sf::Vector2f getCenter();
		void setCenter(sf::Vector2f center);
		~GameObject();
	private:
		sf::RectangleShape m_rect;

		bool m_isBarrier = false;

		void init();
	};

}; // namespace pg