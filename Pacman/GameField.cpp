#include "GameField.hpp"

namespace pg {

	GameField::GameField(sf::Vector2f size, sf::Vector2f cellSize):
		m_size(size),
		m_cellSize(cellSize)
	{
		createGrid();
	}

	void GameField::addAllObjects(std::vector<GameObject> objects) {
		for (auto obj : objects) {
			addObject(obj);
		}
	}

	void GameField::addObject(GameObject &object) {

	}

	void GameField::createGrid() {
		grid.reserve(m_size.x);
		
		for (auto row : grid) {
			row.reserve(m_size.y);
		}
	}


	GameField::~GameField() {

	}

} // namespace pg