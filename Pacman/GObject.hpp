#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Math.hpp"
#include "Singleton.hpp"
#include "SoundManager.hpp"
#include "AnimationManager.hpp"
#include <functional>

namespace pg {

	class GObject {
	public:
		GObject();

		void draw(sf::RenderTarget &window);

		void setAnimations(
			sf::Texture *texture,
			std::vector<std::string> &names,
			std::vector<std::vector<sf::IntRect>> &frames,
			std::vector<std::vector<int>> &durations
		);

		void setTexture(sf::Texture *texture, sf::IntRect textureRect);

		bool intersects(GObject *obj);

		virtual void update(int frameTime);
		virtual void updateSpeed(int frameTime) = 0;
		virtual void updateAnimation(int frameTime) = 0;
		virtual void setStartAnim() = 0;
		virtual void interact(pg::GObject *obj) = 0;

		void updatePos();

		bool isObstacle();
		bool isMovable();
		bool isDead();

		void setPosition(sf::Vector2f coords);
		void setCenter(sf::Vector2f center);
		void setSpeed(sf::Vector2f speed);
		void setSize(sf::Vector2f size);

		sf::Vector2f getPosition();
		sf::Vector2f getCenter();
		sf::Vector2f getSpeed();
		sf::Vector2f getSize();

		void setLeft(float val);
		void setTop(float val);
		void setRight(float val);
		void setBottom(float val);

		float getLeft();
		float getTop();
		float getRight();
		float getBottom();

		sf::FloatRect getBounds();

		void move(sf::Vector2f offset);
		void addToSpeed(sf::Vector2f dSpeed);

		void setPosInGrid(sf::Vector2i *coords);
		sf::Vector2i* getPosInGrid();

		bool die();

		void setOnDead(std::function<void()> onDead);

	    virtual ~GObject();

	protected:
		bool m_isDead = false;
		bool m_isObstacle;
		bool m_isMovable;

		AnimationManager *m_animationManager;

		SoundManager m_sounds;

	private:
		sf::RectangleShape m_rect;
		sf::Vector2f m_speed;
		sf::Vector2i *m_posInGrid;

		std::function<void()> m_onDead;

		void _useAnimation(int frameTime);
	};

}; // namespace pg