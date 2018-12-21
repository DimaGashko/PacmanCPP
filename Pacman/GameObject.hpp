#pragma once

#include <SFML/Graphics.hpp>

namespace pg {

	class GameObject {
	public:
		GameObject();
		void draw(sf::RenderTarget &window);
		GameObject(sf::Texture *texture);
		sf::Vector2f getPosition();
		void setPosition(sf::Vector2f coords);
		~GameObject();
	private:
		sf::RectangleShape m_rect;

		bool m_real;
	};

}; // namespace pg