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
		
	}

	void GameField::addAllObjects(std::vector<GameObject*> objects) {
		for (auto obj : objects) {
			addObject(obj);
		}
	}

	void GameField::addObject(GameObject *object) {
		addObjectToGrid(object);
		
	}

	void GameField::draw(sf::RenderWindow &window, sf::FloatRect visibleRange) {
		forEachObjectsOfRange(visibleRange, [&window](GameObject *obj) {
			obj->draw(window);
		});
	}

	void GameField::update(sf::Vector2f gameSize, int frameTime) {
		std::vector<GameObject*> activeObjects;

		forEachObjectsOfRange(_getActiveRange(gameSize), [&](GameObject *obj1) {
			activeObjects.push_back(obj1);

			auto oldPos = obj1->getPosition();
			auto oldCenter = obj1->getCenter();
			auto oldEndPos = obj1->getEndPos();

			sf::FloatRect candidatesRange(oldPos - m_cellSize, oldPos + m_cellSize);

			forEachObjectsOfRange(candidatesRange, [&](GameObject *obj2) {
				if (!obj1->isObstacle() || !obj2->isObstacle()) {
					//interact only
					return;
				}

				auto obj2Center = obj2->getCenter();
				auto obj2EndPos = obj2->getEndPos();

				obj1->updatePos();
				auto newPos = obj1->getPosition();
				bool intersects = obj1->intersects(obj2);
				obj1->setPosition(oldPos);

				if (!intersects) {
					return;
				}
				
				sf::Vector2f dir = newPos - oldPos;


				bool hIntersects;

				if (dir.x < 0) {
					hIntersects = Math::intersectsL2(
						oldCenter, obj2Center,

					);
				}



				auto hSide = (dir.x < 0) ? eSides::Right : eSides::Left;
				auto vSide = (dir.y < 0) ? eSides::Bottom : eSides::Top;

			});
		});

		for (auto obj : activeObjects) {
			obj->update();
			//addObjectToGrid(obj);
		}
	}

	sf::FloatRect GameField::_getActiveRange(sf::Vector2f gameSize) {
		auto size = gameSize * 3.f;
		auto coords = m_player->getPosition() - size / 2.f;

		return sf::FloatRect(coords, size);
	}

	void GameField::addAllObjectsToGrid(std::vector<GameObject*> objects) {
		for (auto obj : objects) {
			addObjectToGrid(obj);
		}
	}

	void GameField::addObjectToGrid(GameObject *object) {
		sf::Vector2f objCoords = object->getPosition();
		sf::Vector2i coords = _getCoordsInGrid(objCoords);
		
		//Oбъект уже есть в сетке
		if (m_objectCoords.count(object) != 0) {
			auto prev = m_objectCoords[object];
			
			if (prev.x == coords.x && prev.y == coords.y) {
				//И уже находится в нужной ячейке
				return;
			}
			else {
				if (!_hasCell(prev)) return;
				auto cell = m_grid[prev.x][prev.y];
				std::vector<GameObject*> newCell;

				for (auto item : cell) {
					if (item != object) {
						newCell.push_back(item);
					}
				}
				
				m_grid[prev.x][prev.y] = newCell;
			}
		}

		if (!_hasCell(coords)) return;
		auto &cell = m_grid[coords.x][coords.y];
		
		m_objectCoords[object] = sf::Vector2i((int)objCoords.x, (int)objCoords.y);
		cell.push_back(object);
	}

	template<typename F>
	void GameField::forEachObjectsOfRange(sf::FloatRect range, F &&func) {
		auto _range = sf::IntRect(
			_getCoordsInGrid(sf::Vector2f(range.left, range.top)),
			_getCoordsInGrid(sf::Vector2f(range.width, range.height))
		);

		for (int x = _range.left; x <= _range.left + _range.width; x++) {
			for (int y = _range.top; y <= _range.top + _range.height; y++) {

				if (!_hasCell(sf::Vector2i(x, y))) continue;

				for (auto obj : m_grid[x][y]) {
					auto coords = obj->getPosition();

					bool check = (coords.x >= range.left && coords.y >= range.top
						&& coords.x <= (range.left + range.width)
						&& coords.y <= (range.top + range.height)
						);

					if (check) func(obj);
				}
			}
		}

	}

	inline bool GameField::_hasCell(sf::Vector2i coords) {
		return coords.x >= 0 && coords.y >= 0
			&& coords.y < m_size.y && coords.x < m_size.x;
	}

	inline sf::Vector2i GameField::_getCoordsInGrid(sf::Vector2f coords) {
		return sf::Vector2i(int(coords.x / m_cellSize.x), int(coords.y / m_cellSize.y));
	}

	void GameField::setPlayer(Actor* player) {
		m_player = player;
	}

	Actor* GameField::getPlayer() {
		return m_player;
	}

	GameField::~GameField() {

		for (auto row : m_grid) {
			for (auto cell : row) {
				for (auto obj : cell) {
					delete obj;
				}
			}
		}

	}

} // namespace pg