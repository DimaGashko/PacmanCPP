#include "GameField.hpp"

namespace pg {

	GameField::GameField(sf::Vector2f size, sf::Vector2f cellSize):
		m_size(size),
		m_cellSize(cellSize)
	{
		createGrid();
	}

	void GameField::addAllObjects(std::vector<GameObject*> objects) {
		for (auto obj : objects) {
			addObject(obj);
		}
	}

	void GameField::addObject(GameObject *object) {
		sf::Vector2i coords = getCoordsInGrid(object->getPosition());
		
		//Oбъект уже есть в сетке
		if (m_objectCoords.count(object) != 0) {
			auto prev = m_objectCoords[object];
			
			if (prev.x == coords.x && prev.y == coords.y) {
				//И уже находится в нужной ячейке
				return;
			}
			else {

			}
		}


	}

	void GameField::createGrid() {
		m_grid.reserve(m_size.x);
		
		for (auto row : m_grid) {
			row.reserve(m_size.y);
		}
	}

	bool GameField::hasCell(sf::Vector2i coords) {
		return coords.x >= 0 && coords.y >= 0
			&& coords.y < m_size.y && coords.x < m_size.x;
	}

	sf::Vector2i GameField::getCoordsInGrid(sf::Vector2f coords) {
		return sf::Vector2i(coords.x / m_cellSize.x, coords.y / m_cellSize.y);
	}

	GameField::~GameField() {

	}

} // namespace pg