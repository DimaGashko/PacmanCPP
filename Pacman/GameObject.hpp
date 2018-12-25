#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Math.hpp"

namespace pg {

	class GameObject {
	public:
		GameObject();
		void draw(sf::RenderTarget &window);
		GameObject(sf::Texture *texture);

		void update();
		void updatePos();

		void setBottomLeft(sf::Vector2f coords);
		void setTopRight(sf::Vector2f coords);
		void setPosition(sf::Vector2f coords);
		void setCenter(sf::Vector2f center);
		void setEndPos(sf::Vector2f coords);
		void setSpeed(sf::Vector2f speed);
		void setSize(sf::Vector2f size);

		sf::Vector2f getBottomLeft();
		sf::Vector2f getTopRight();
		sf::Vector2f getPosition();
		sf::Vector2f getCenter();
		sf::Vector2f getEndPos();
		sf::Vector2f getSpeed();
		sf::Vector2f getSize();

		void setPosInGrid(sf::Vector2i *coords);
		sf::Vector2i* getPosInGrid();

		bool isDead();
		bool isObstacle();
		bool isMovable();

		sf::FloatRect getBounds();

		void move(sf::Vector2f offset);
		void addToSpeed(sf::Vector2f dSpeed);

		bool intersects(GameObject *obj);

	    virtual ~GameObject();

	protected:

	private:
		sf::RectangleShape m_rect;
		sf::Vector2f m_speed;
		sf::Vector2i *m_posInGrid;

		bool m_isDead = false;
		bool m_isObstacle;
		bool m_isMovable;

		virtual void _initProperties();

	};

}; // namespace pg