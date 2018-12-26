#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Math.hpp"
#include "AnimationManager.hpp"

namespace pg {

	class GameObject {
	public:
		GameObject();

		void draw(sf::RenderTarget &window);

		void setAnimations(
			sf::Texture *texture,
			std::vector<std::string> &names,
			std::vector<std::vector<sf::IntRect>> &frames,
			std::vector<std::vector<int>> &durations
		);

		void setTexture(sf::Texture *texture, sf::IntRect textureRect);

		bool intersects(GameObject *obj);

		virtual void update(int frameTime);
		virtual void updateAnimation(int frameTime);
		void updatePos();

		bool isObstacle();
		bool isMovable();
		bool isDead();

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

		sf::FloatRect getBounds();

		void move(sf::Vector2f offset);
		void addToSpeed(sf::Vector2f dSpeed);

		void setPosInGrid(sf::Vector2i *coords);
		sf::Vector2i* getPosInGrid();

	    virtual ~GameObject();

	protected:
		bool m_isDead = false;
		bool m_isObstacle;
		bool m_isMovable;

		pg::AnimationManager *m_animationManager;

	private:
		sf::RectangleShape m_rect;
		sf::Vector2f m_speed;
		sf::Vector2i *m_posInGrid;

		void _useAnimation(int frameTime);
	};

}; // namespace pg