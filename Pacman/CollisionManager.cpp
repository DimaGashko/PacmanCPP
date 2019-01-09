#include "CollisionManager.hpp"

namespace pg {

	CollisionManager::CollisionManager() {

	}

	void CollisionManager::update(Grid &grid, sf::FloatRect activeRange, int frameTime) {
		std::vector<GObject*> activeObjects;
		grid.getObjectsOfRange(activeRange, activeObjects);

		for (auto &obj : activeObjects) {
			obj->update(frameTime);
		}

		sf::Vector2f cellSize(grid.getCellSize());

		for (auto &obj1 : activeObjects) {
			auto oldPos = obj1->getPosition();
			sf::FloatRect candidatesRange(oldPos - cellSize, cellSize * 2.f);

			std::vector<GObject*> candidates;
			grid.getObjectsOfRange(candidatesRange, candidates, 50);

			for (auto &obj2 : candidates) {
				obj1->move(obj1->getSpeed());
				bool intersects = obj1->intersects(obj2);
				obj1->setPosition(oldPos);
				if (!intersects) continue;

				proc(obj1, obj2);
				obj1->interact(obj2);
			}
		}

		for (auto &obj : activeObjects) {
			auto oldPos = obj->getPosition();
			obj->updatePos();
			auto newPos = obj->getPosition();

			if (oldPos.x != newPos.x || oldPos.y != newPos.y) {
				grid.add(obj);
			}

		}
	}

	void CollisionManager::proc(GObject *obj1, GObject *withObj) {
		bool check = (!obj1->isMovable() && !withObj->isMovable())
			|| !withObj->isObstacle();

		if (check) {
			return;
		}

		auto speed = obj1->getSpeed();
		auto intersectSide = _getCollisionSide(obj1, withObj);

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

	CollisionManager::_eSides CollisionManager::_getCollisionSide(GObject *obj1, GObject *obj2) {
		auto o1 = obj1->getCenter();
		auto o2 = obj2->getCenter();

		sf::Vector2f leftTop(obj2->getPosition());
		sf::Vector2f leftBottom(obj2->getLeft(), obj2->getBottom());
		sf::Vector2f rightTop(obj2->getRight(), obj2->getTop());
		sf::Vector2f rightBottom(obj2->getRight(), obj2->getBottom());

		if (Math::intersectsL2(o1, o2, rightTop, rightBottom)) return Right;
		if (Math::intersectsL2(o1, o2, leftTop, leftBottom)) return Left;

		if (Math::intersectsL2(o1, o2, leftBottom, rightBottom)) return Bottom;
		if (Math::intersectsL2(o1, o2, leftTop, rightTop)) return Top;

		// Например, если объект внутри другого объекта
		return _eSides::None;
	}

	CollisionManager::~CollisionManager() {

	}

}; // namepspace pg