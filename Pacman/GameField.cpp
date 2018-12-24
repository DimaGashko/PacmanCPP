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
		forEachObjectsOfRange(_getActiveRange(gameSize), [&](GameObject *obj1) {
			auto oldPos = obj1->getPosition();
			sf::FloatRect candidatesRange(oldPos - m_cellSize, oldPos + m_cellSize);

			forEachObjectsOfRange(candidatesRange, [&](GameObject *obj2) {
				obj1->move(obj1->getSpeed());
				bool intersects = obj1->intersects(obj2);
				obj1->setPosition(oldPos);
				if (!intersects) return; 
				
				procCollision(obj1, obj2);
				//interact
			});

			obj1->update();
		});
	}

	void GameField::procCollision(GameObject *obj1, GameObject *obj2) {
		if (!obj1->isObstacle() || !obj2->isObstacle()) {
			return;
		}

		auto speed = obj1->getSpeed();
		auto obj2Speed = obj2->getSpeed();

		if (abs(speed.x * speed.y) < abs(obj2Speed.x * obj2Speed.y)) {
			return;
		}

		auto intersectSide = _getCollisionSide(obj1, obj2);

		if ((intersectSide & Left) != 0) {
			obj1->setSpeed(sf::Vector2f(-0.1, speed.y));
			obj1->move(sf::Vector2f(-1, 0));
		}
		if ((intersectSide & Top) != 0) {
			obj1->setSpeed(sf::Vector2f(speed.x, -0.1));
			obj1->move(sf::Vector2f(0, -1));
		}
		if ((intersectSide & Right) != 0) {
			obj1->setSpeed(sf::Vector2f(0.1, speed.y));
			obj1->move(sf::Vector2f(1, 0));
		}
		if ((intersectSide & Bottom) != 0) {
			obj1->setSpeed(sf::Vector2f(speed.x, 0.1));
			obj1->move(sf::Vector2f(0, 1));
		}
		if (intersectSide == None) {
			//obj1->setSpeed(sf::Vector2f(0, 0));
		}
		
		std::cout << intersectSide << typeid(*obj1).name() << " ";

		if ((intersectSide & Left) != 0) std::cout << "Left ";
		if ((intersectSide & Top) != 0) std::cout << "Top ";
		if ((intersectSide & Right) != 0) std::cout << "Right ";
		if ((intersectSide & Bottom) != 0) std::cout << "Bottom ";
		if (intersectSide == None) std::cout << "None ";
		
		std::cout << std::endl;
	}

	int GameField::_getCollisionSide(GameObject *obj1, GameObject *obj2) {
		auto speed = obj1->getSpeed();

		auto o1 = obj1->getCenter();
		auto o2 = obj2->getCenter();

		auto obj2Pos = obj2->getPosition();
		auto obj2TopRight = obj2->getTopRight();
		auto obj2EndPos = obj2->getEndPos();
		auto obj2BottomLeft = obj2->getBottomLeft();

		int side = (int)eSides::None;

		if (Math::intersectsL2(o1, o2, obj2TopRight, obj2EndPos)) side = (side | (int)eSides::Right);
		if (Math::intersectsL2(o1, o2, obj2Pos, obj2BottomLeft)) side = (side | (int)eSides::Left);
		
		if (Math::intersectsL2(o1, o2, obj2BottomLeft, obj2EndPos)) side = (side | (int)eSides::Bottom);
		if (Math::intersectsL2(o1, o2, obj2Pos, obj2TopRight)) side = (side | (int)eSides::Top);

		return side;
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