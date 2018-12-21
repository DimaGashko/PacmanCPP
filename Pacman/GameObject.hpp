#pragma once

#include <SFML/Graphics.hpp>

namespace pg {

	class GameObject {
	public:
		GameObject();
		void draw(sf::RenderTarget &window);
		GameObject(sf::Vector2f position);
		sf::Vector2f getPosition();
		~GameObject();
	private:
		sf::RectangleShape m_rect;
	};

}; // namespace pg