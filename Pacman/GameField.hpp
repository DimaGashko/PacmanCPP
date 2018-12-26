#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <typeinfo>

#include "Math.hpp"
#include "GameObject.hpp"
#include "Actor.hpp"
#include "Point.hpp"

namespace pg {

	class GameField {
	public:
		GameField();
		GameField(sf::Vector2i size, sf::Vector2i cellSize);

		void addAllObjects(std::vector<GameObject*> objects);
		void addObject(GameObject *object);

		void draw(sf::RenderWindow &window, sf::FloatRect visibleRange);
		void update(sf::Vector2f gameSize, int frameTime);

		void setPlayer(Actor *actor);
		Actor* getPlayer();

		bool checkWon();

		enum eSides { Left, Top, Right, Bottom, None };

		~GameField();
	
	private:
		bool m_isWon = false;
		int m_pointsCount = 0;
		Actor *m_player;

		sf::Vector2f m_size;
		sf::Vector2f m_cellSize;
		 
		// Cетка игры
		std::vector<std::vector<std::vector<GameObject *>>> m_grid;

		void getObjectsOfRange(sf::FloatRect range, std::vector<GameObject*> &res, int maxSize = 5000);

		// Добавляет объект в сетку
		// Если объект уже был в сетке, то от сначала удаляется с предыдущего места
		void addToGrid(GameObject *object);

		void removeFromGrid(GameObject *object);

		sf::FloatRect _getActiveRange(sf::Vector2f gameSize);

		bool _hasCell(sf::Vector2i coords);
		sf::Vector2i _getCoordsInGrid(sf::Vector2f coords);

		void procCollision(GameObject *obj1, GameObject *obj2);

		// Возвращает сторону obj2, с которой столкнулся obj1
		eSides _getCollisionSide(GameObject *obj1, GameObject *obj2);
	};

} // namespace pg
