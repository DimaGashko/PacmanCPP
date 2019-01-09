#pragma once

#include <SFML/Graphics.hpp>

#include "GObject.hpp"

namespace pg {

	class Grid {
	public:
		Grid();
		Grid(sf::Vector2i size, sf::Vector2i cellSize);

		// Добавляет объект в сетку
		// Если объект уже был в сетке, то от сначала удаляется с предыдущего места
		void add(GObject *object);

		void remove(GObject *object);

		void getObjectsOfRange(sf::FloatRect range, std::vector<GObject*> &res, int maxSize = 5000);

		sf::Vector2i getSize();
		sf::Vector2i getCellSize();

		~Grid();

	private:
		sf::Vector2i m_size;
		sf::Vector2i m_cellSize;

		std::vector<std::vector<std::vector<GObject *>>> m_grid;

		bool _hasCell(sf::Vector2i coords);
		sf::Vector2i _getCoordsInGrid(sf::Vector2f coords);
	};

}; // namespace pg
