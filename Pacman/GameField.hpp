#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#include "GameObject.hpp"
#include "Actor.hpp"

namespace pg {

	class GameField {
	public:
		GameField();
		GameField(sf::Vector2i size, sf::Vector2i cellSize);

		void addAllObjects(std::vector<GameObject*> objects);
		void addObject(GameObject *object);

		void draw(sf::RenderWindow &window, std::vector<GameObject*> visibleObjects);
		void update(sf::Vector2f gameSize, int frameTime);

		void setPlayer(Actor *actor);
		Actor* getPlayer();

		/**
		 * Возвращает все объекты находящихся в переданном диапазоне
		 * @param start Левый верхний угол диапазона
		 * @param ned Правый нижний угол диапазона
		*/
		/*template<typename F>
		void forEach(F &&func) {
			for (int i = 0; i < 10; i++) {
				func();
			}
		}*/

		std::vector<GameObject*> getObjectsOfRange(sf::Vector2f start, sf::Vector2f end);

		~GameField();
	
	private:
		int m_pointsCount = 0;
		Actor *m_player;

		sf::Vector2f m_size;
		sf::Vector2f m_cellSize;
		 
		// Cетка игры
		std::vector<std::vector<std::vector<GameObject *>>> m_grid;

		// Объект, содержащий координаты всех объектов в сетке по их id
	    // Используется для быстрого определения где в данный момент находится объект
	    // (используется, что бы удаялять объект из предыдущего места)
		std::unordered_map<GameObject*, sf::Vector2i> m_objectCoords;
		
		/**
		 * Добавляет переданные объекты в сетку
		 * Если какой-то объект уже был в сетке, то от сначала удаляется с предыдущего места
		 * @param object добавляемый объект
		 */
		void addAllObjectsToGrid(std::vector<GameObject*> objects);

		/**
		 * Добавляет объект в сетку
		 * Если объект уже был в сетке, то от сначала удаляется с предыдущего места
		 * @param object добавляемый объект
		 */
		void addObjectToGrid(GameObject *object);

		std::vector<GameObject*> _getActiveObjects(sf::Vector2f gameSize);

		bool _hasCell(sf::Vector2i coords);
		sf::Vector2i _getCoordsInGrid(sf::Vector2f coords);
	};

} // namespace pg
