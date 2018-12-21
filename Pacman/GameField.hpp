#pragma once

#include <vector>

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
		void addAllObjects(std::vector<GameObject> objects);

		/**
		* Добавляет объект в сетку
		* Если объект уже был в сетке, то от сначала удаляется с предыдущего места
		* @param object добавляемый объект
		*/
		void addObject(GameObject &object);

		~GameField();
	
	private:
		sf::Vector2f m_size;
		sf::Vector2f m_cellSize;
		 
		std::vector<std::vector<std::vector<GameObject *>>> grid;

		void createGrid();
		
	};

} // namespace pg
