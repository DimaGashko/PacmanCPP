#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "Math.hpp"
#include "Grid.hpp"
#include "CollisionManager.hpp"
#include "GObject.hpp"
#include "Actor.hpp"
#include "Point.hpp"

namespace pg {

	class GField {
	public:
		GField();
		GField(sf::Vector2i size, sf::Vector2i cellSize);

		void addAllObjects(std::vector<GObject*> objects);
		void addObject(GObject *object);

		void draw(sf::RenderWindow &window, sf::FloatRect visibleRange);
		void update(sf::Vector2f gameSize, int frameTime);

		void setPlayer(Actor *actor);
		Actor* getPlayer();

		bool checkWon();
		bool checkGameOver();

		~GField();
	
	private:
		Grid m_grid;
		CollisionManager m_collisionManager;
		Actor *m_player;

		bool m_isWon = false;
		bool m_gameOver = false;
		int m_pointsCount = 0;

		void gameOver();
		
		sf::FloatRect _getActiveRange(sf::Vector2f gameSize);
	};

} // namespace pg
