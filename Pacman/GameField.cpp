#include "GameField.hpp"

namespace pg {

	GameField::GameField() :
		GameField(sf::Vector2i(10, 10), sf::Vector2i(16, 16))
	{
	
	}

	GameField::GameField(sf::Vector2i size, sf::Vector2i cellSize) :
		m_size(size),
		m_cellSize(cellSize),
		m_grid(size.x, std::vector<std::vector<GameObject*>>(size.y))
	{
		createGrid();
	}

	void GameField::addAllObjects(std::vector<GameObject*> objects) {
		for (auto obj : objects) {
			addObject(obj);
		}
	}

	void GameField::addObject(GameObject *object) {
		sf::Vector2f objCoords = object->getPosition();
		sf::Vector2i coords = _getCoordsInGrid(objCoords);
		
		//O����� ��� ���� � �����
		if (m_objectCoords.count(object) != 0) {
			auto prev = m_objectCoords[object];
			
			if (prev.x == coords.x && prev.y == coords.y) {
				//� ��� ��������� � ������ ������
				return;
			}
			else {
				if (!_hasCell(prev)) return;
				auto cell = m_grid[prev.x][prev.y];

				auto pos = std::find(cell.begin(), cell.end(), object);
				cell.erase(pos);
			} 
		}

		if (!_hasCell(coords)) return;
		auto &cell = m_grid[coords.x][coords.y];
		
		m_objectCoords[object] = sf::Vector2i(objCoords.x, objCoords.y);
		cell.push_back(object);
	}

	std::vector<GameObject*> GameField::getObjectsOfRange(sf::Vector2f start, sf::Vector2f end) {
		std::vector<GameObject *> result;

		//���������� ������ ���� ���������������
		if (start.x > end.x) std::swap(start.x, end.x);
		if (start.y > end.y) std::swap(start.y, end.y);

		auto _start = _getCoordsInGrid(start);
		auto _end = _getCoordsInGrid(end);

		for (int x = _start.x; x <= _end.x; x++) {
			for (int y = _start.y; y <= _end.y; y++) {

				if (!_hasCell(sf::Vector2i(x, y))) continue;
				auto cell = m_grid[x][y];

				for (auto obj : cell) {
					auto coords = obj->getPosition();

					bool check = (coords.x >= start.x && coords.x <= end.x
						&& coords.y >= start.y && coords.y <= end.y);

					if (check) result.push_back(obj);
				}
			}
		}

		return result;
	}

	void GameField::createGrid() {
		

	}

	bool GameField::_hasCell(sf::Vector2i coords) {
		return coords.x >= 0 && coords.y >= 0
			&& coords.y < m_size.y && coords.x < m_size.x;
	}

	sf::Vector2i GameField::_getCoordsInGrid(sf::Vector2f coords) {
		return sf::Vector2i(coords.x / m_cellSize.x, coords.y / m_cellSize.y);
	}

	GameField::~GameField() {

	}

} // namespace pg