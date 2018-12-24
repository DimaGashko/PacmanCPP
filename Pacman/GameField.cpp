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
			sf::FloatRect candidatesRange(oldPos - m_cellSize, oldPos + m_cellSize);

			int count = 0;
			forEachObjectsOfRange(candidatesRange, [&](GameObject *obj2) {
				count++;
				obj1->move(obj1->getSpeed());
				bool intersects = obj1->intersects(obj2);
				obj1->setPosition(oldPos);
				if (!intersects) return; 
				
				procCollision(obj1, obj2);
				//interact
			});

			//std::cout << count << std::endl;

			obj1->update();
		});

		bool playerIsActive = false;
		for (auto obj : activeObjects) {
			if (obj != m_player) continue;
			playerIsActive = true;
			break;
		}
		   
		if (!playerIsActive) {
			activeObjects.push_back(m_player);
		}

		for (auto obj : activeObjects) {
			auto oldPos = obj->getPosition();
			obj->update();
			auto newPos = obj->getPosition();

			if (oldPos.x != newPos.x || oldPos.y != newPos.y) {
				addObjectToGrid(obj);
			}
			
		}
	}

	void GameField::procCollision(GameObject *obj1, GameObject *obj2) {
		if (!obj1->isObstacle() || !obj2->isObstacle()) {
			return;
		}

		auto speed = obj1->getSpeed();
		auto obj2Speed = obj2->getSpeed();

		auto intersectSide = _getCollisionSide(obj1, obj2);

		if (intersectSide == Left) {
			obj1->setSpeed(sf::Vector2f(-0.01f, speed.y));
			obj1->move(sf::Vector2f(-1.f, 0.f));
		}
		else if (intersectSide == Top) {
			obj1->setSpeed(sf::Vector2f(speed.x, -0.01f));
			obj1->move(sf::Vector2f(0.f, -1.f));
		}
		else if (intersectSide == Right) {
			obj1->setSpeed(sf::Vector2f(0.01f, speed.y));
			obj1->move(sf::Vector2f(1.f, 0.f));
		}
		else if (intersectSide == Bottom) {
			obj1->setSpeed(sf::Vector2f(speed.x, 0.01f));
			obj1->move(sf::Vector2f(0.f, 1.f));
		}
		else obj1->setSpeed(sf::Vector2f(0.f, 0.f));
	}

	GameField::eSides GameField::_getCollisionSide(GameObject *obj1, GameObject *obj2) {
		auto speed = obj1->getSpeed();

		auto o1 = obj1->getCenter();
		auto o2 = obj2->getCenter();

		auto obj2Pos = obj2->getPosition();
		auto obj2TopRight = obj2->getTopRight();
		auto obj2EndPos = obj2->getEndPos();
		auto obj2BottomLeft = obj2->getBottomLeft();

		if (Math::intersectsL2(o1, o2, obj2TopRight, obj2EndPos)) return eSides::Right;
		if (Math::intersectsL2(o1, o2, obj2Pos, obj2BottomLeft)) return eSides::Left;
		
		if (Math::intersectsL2(o1, o2, obj2BottomLeft, obj2EndPos)) return eSides::Bottom;
		if (Math::intersectsL2(o1, o2, obj2Pos, obj2TopRight)) return eSides::Top;

		// Например, если объект внутри другого объекта
		return eSides::None;
	}

	sf::FloatRect GameField::_getActiveRange(sf::Vector2f gameSize) {
		auto size = gameSize * 1.f;
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
		auto prev = object->getPosInGrid();

		if (prev) {			
			if (prev->x == coords.x && prev->y == coords.y) {
				//И уже находится в нужной ячейке
				return;
			}
			else {
				if (!_hasCell(*prev)) return;
				auto &cell = m_grid[prev->x][prev->y];
				auto size = cell.size();

				std::vector<GameObject*> newCell(size - 1);

				for (int i = 0; i < size; i++) {
					if (cell[i] != object) {
						newCell[i] = cell[i];
					}
				}
				
				m_grid[prev->x][prev->y] = newCell;
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