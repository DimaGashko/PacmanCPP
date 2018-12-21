#pragma once

#include <vector>
#include <unordered_map>

#include "GameObject.hpp"

namespace pg {

	class GameField {
	public:
		GameField(sf::Vector2f size, sf::Vector2f cellSize);

		/**
		* Добавляет переданные объекты в сетку
		* Если какой-то объект уже был в сетке, то от сначала удаляется с предыдущего места
		* @param object добавляемый объект
		*/
		void addAllObjects(std::vector<GameObject*> objects);

		/**
		* Добавляет объект в сетку
		* Если объект уже был в сетке, то от сначала удаляется с предыдущего места
		* @param object добавляемый объект
		*/
		void addObject(GameObject *object);

		~GameField();
	
	private:
		sf::Vector2f m_size;
		sf::Vector2f m_cellSize;
		 
		// Cетка игры
		std::vector<std::vector<std::vector<GameObject *>>> m_grid;

		// Объект, содержащий координаты всех объектов в сетке по их id
	    // Используется для быстрого определения где в данный момент находится объект
	    // (используется, что бы удаялять объект из предыдущего места)
		std::unordered_map<GameObject*, sf::Vector2i> m_objectCoords;

		sf::Vector2i getCoordsInGrid(sf::Vector2f);

		void createGrid();
		
	};

} // namespace pg
