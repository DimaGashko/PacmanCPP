#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

namespace pg {

	class GameObject {
	public:
		GameObject();
		void draw(sf::RenderTarget &window);
		GameObject(sf::Texture *texture);

		void update();
		void updatePos();

		void setPosition(sf::Vector2f coords);
		void setCenter(sf::Vector2f center);
		void setSpeed(sf::Vector2f speed);
		void setSize(sf::Vector2f size);

		sf::Vector2f getPosition();
		sf::Vector2f getCenter();
		sf::Vector2f getSpeed();
		sf::Vector2f getSize();

		sf::FloatRect getBounds();

		void move(sf::Vector2f offset);
		void addToSpeed(sf::Vector2f dSpeed);

		bool intersects(GameObject *obj);

		~GameObject();
	private:
		sf::RectangleShape m_rect;
		sf::Vector2f m_speed;

		bool m_isBarrier = false;

		void init();

	};

}; // namespace pg