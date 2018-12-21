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
		auto coords = getCoordsInGrid(object.getPosition());
		
		//O����� ��� ���� � �����
		if (m_objectCoords.count(object) != 0) {
			auto prev = m_objectCoords[object];
			
			if (prev.x == coords.x && prev.y == coords.y) {
				//� ���� �� ��� ��������� � ������ ������, �� ������ �� ������
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


	GameField::~GameField() {

	}

} // namespace pg