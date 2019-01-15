#include "Grid.hpp"

namespace pg {

	Grid::Grid() :
		Grid(sf::Vector2i(10, 10), sf::Vector2i(16, 16))
	{
	
	}

	Grid::Grid(sf::Vector2i size, sf::Vector2i cellSize) :
		m_size(size),
		m_cellSize(cellSize),
		m_grid(m_size.x, std::vector<std::list<GObject*>>(m_size.y))
	{

	}

	void Grid::add(GObject *object) {
		sf::Vector2f objCoords = object->getPosition();
		sf::Vector2i coords = _getCoordsInGrid(objCoords);
		sf::Vector2i *prev = object->getPosInGrid();

		//Oбъект уже есть в сетке

		if (prev) {
			if (prev->x == coords.x && prev->y == coords.y) {
				//И уже находится в нужной ячейке
				return;
			}
			else {
				remove(object);
			}
		}
		else {
			object->setPosInGrid(new sf::Vector2i());
		}

		if (!_hasCell(coords)) return;
		auto &cell = m_grid[coords.x][coords.y];

		auto posInGrid = object->getPosInGrid();

		posInGrid->x = coords.x;
		posInGrid->y = coords.y;

		cell.push_back(object);
	}

	void Grid::remove(GObject *object) {
		if (!object) return;

		auto coords = object->getPosInGrid();

		if (!_hasCell(*coords)) return;
		auto &cell = m_grid[coords->x][coords->y];

		cell.remove(object);
	}

	bool removeIf(GObject *obj) {
		return !obj || obj->isDead();
	}

	void Grid::getObjectsOfRange(sf::FloatRect range, std::vector<GObject*> &res, int maxSize) {
		std::vector<GObject*> tmp(maxSize);
		int len = 0;

		auto _range = sf::IntRect(
			_getCoordsInGrid(sf::Vector2f(range.left, range.top)),
			_getCoordsInGrid(sf::Vector2f(range.width, range.height))
		);

		std::vector<GObject*> toDelete;

		for (int x = _range.left; x <= _range.left + _range.width; x++) {
			for (int y = _range.top; y <= _range.top + _range.height; y++) {

				if (!_hasCell(sf::Vector2i(x, y))) continue;
				auto &cell = m_grid[x][y];

				for (auto obj : cell) {
					if (!obj) continue;

					if (obj->isDead()) {
						toDelete.push_back(obj);
						continue;
					}

					tmp[len++] = obj;
				}

			}
		}

		for (auto obj : toDelete) {
			remove(obj);
		}

		res.resize(len);

		std::move(tmp.begin(), tmp.begin() + len, res.begin());
	}

	sf::Vector2i Grid::getSize() {
		return m_size;
	}

	sf::Vector2i Grid::getCellSize() {
		return m_cellSize;
	}

	inline bool Grid::_hasCell(sf::Vector2i coords) {
		return coords.x >= 0 && coords.y >= 0
			&& coords.y < m_size.y && coords.x < m_size.x;
	}

	inline sf::Vector2i Grid::_getCoordsInGrid(sf::Vector2f coords) {
		return sf::Vector2i(int(coords.x / m_cellSize.x), int(coords.y / m_cellSize.y));
	}

	Grid::~Grid() {

		for (auto &row : m_grid) {
			for (auto &cell : row) {
				for (auto &obj : cell) {
					delete obj;
				}
			}
		}

	}

}
