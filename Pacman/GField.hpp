#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <typeinfo>

#include "Math.hpp"
#include "Grid.hpp"
#include "GObject.hpp"
#include "Actor.hpp"
#include "Point.hpp"

namespace pg {

	class GField {
	public:
		GField();
		GField(sf::Vector2i size, sf::Vector2f cellSize);

		void addAllObjects(std::vector<GObject*> objects);
		void addObject(GObject *object);

		void draw(sf::RenderWindow &window, sf::FloatRect visibleRange);
		void update(sf::Vector2f gameSize, int frameTime);

		void setPlayer(Actor *actor);
		Actor* getPlayer();

		bool checkWon();
		bool checkGameOver();

		enum eSides { Left, Top, Right, Bottom, None };

		~GField();
	
	private:
		Grid grid;

		bool m_isWon = false;
		bool m_gameOver = false;
		int m_pointsCount = 0;
		Actor *m_player; 

		void gameOver();

		sf::FloatRect _getActiveRange(sf::Vector2f gameSize);

		void procCollision(GObject *obj1, GObject *obj2);

		// ¬озвращает сторону obj2, с которой столкнулс€ obj1
		eSides _getCollisionSide(GObject *obj1, GObject *obj2);
	};

} // namespace pg
