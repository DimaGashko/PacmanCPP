#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <typeinfo>

#include "Math.hpp"
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

		enum eSides { Left, Top, Right, Bottom, None };

		~GField();
	
	private:
		bool m_isWon = false;
		bool m_gameOver = false;
		int m_pointsCount = 0;
		Actor *m_player;

		sf::Vector2f m_size;
		sf::Vector2f m_cellSize;
		 
		// Cетка игры
		std::vector<std::vector<std::vector<GObject *>>> m_grid;

		void getObjectsOfRange(sf::FloatRect range, std::vector<GObject*> &res, int maxSize = 5000);

		// Добавляет объект в сетку
		// Если объект уже был в сетке, то от сначала удаляется с предыдущего места
		void addToGrid(GObject *object);

		void removeFromGrid(GObject *object);

		void gameOver();

		sf::FloatRect _getActiveRange(sf::Vector2f gameSize);

		bool _hasCell(sf::Vector2i coords);
		sf::Vector2i _getCoordsInGrid(sf::Vector2f coords);

		void procCollision(GObject *obj1, GObject *obj2);

		// Возвращает сторону obj2, с которой столкнулся obj1
		eSides _getCollisionSide(GObject *obj1, GObject *obj2);
	};

} // namespace pg
