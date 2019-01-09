#include "GField.hpp"

namespace pg {

	GField::GField()
	{

	}

	GField::GField(sf::Vector2i size, sf::Vector2f cellSize) :
		grid(size, cellSize)
	{
	
	}

	void GField::addAllObjects(std::vector<GObject*> objects) {
		for (auto &obj : objects) {
			addObject(obj);
		}
	}

	void GField::addObject(GObject *object) {
		if (dynamic_cast<Point*>(object) != nullptr) {
			m_pointsCount++;

			object->setOnDead([&] {
				m_pointsCount--;

				std::cout << "Points: " << m_pointsCount << std::endl;
			});
		}

		grid.add(object);

	}

	void GField::draw(sf::RenderWindow &window, sf::FloatRect visibleRange) {
		std::vector<GObject*> visibleObjects;
		grid.getObjectsOfRange(visibleRange, visibleObjects);

		for (auto &obj : visibleObjects) {
			obj->draw(window);
		}
	}

	void GField::update(sf::Vector2f gameSize, int frameTime) {
		std::vector<GObject*> activeObjects;
		grid.getObjectsOfRange(_getActiveRange(gameSize), activeObjects);

		for (auto &obj : activeObjects) {
			obj->update(frameTime);
		}

		auto cellSize2 = grid.getCellSize() * 2.f;

		for (auto &obj1 : activeObjects) {
			auto oldPos = obj1->getPosition();
			sf::FloatRect candidatesRange(oldPos - grid.getCellSize(), cellSize2);

			std::vector<GObject*> candidates;
			grid.getObjectsOfRange(candidatesRange, candidates, 50);

			for (auto &obj2 : candidates) {
				obj1->move(obj1->getSpeed());
				bool intersects = obj1->intersects(obj2);
				obj1->setPosition(oldPos);
				if (!intersects) continue;

				procCollision(obj1, obj2);
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

	void GField::procCollision(GObject *obj1, GObject *obj2) {
		if (!obj1->isMovable() || !obj2->isObstacle()) {
			return;
		}

		auto speed = obj1->getSpeed();
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

	GField::eSides GField::_getCollisionSide(GObject *obj1, GObject *obj2) {
		auto o1 = obj1->getCenter();
		auto o2 = obj2->getCenter();

		sf::Vector2f leftTop(obj2->getPosition());
		sf::Vector2f leftBottom(obj2->getLeft(), obj2->getBottom());
		sf::Vector2f rightTop(obj2->getRight(), obj2->getTop());
		sf::Vector2f rightBottom(obj2->getRight(), obj2->getBottom());

		if (Math::intersectsL2(o1, o2, rightTop, rightBottom)) return eSides::Right;
		if (Math::intersectsL2(o1, o2, leftTop, leftBottom)) return eSides::Left;

		if (Math::intersectsL2(o1, o2, leftBottom, rightBottom)) return eSides::Bottom;
		if (Math::intersectsL2(o1, o2, leftTop, rightTop)) return eSides::Top;

		// Например, если объект внутри другого объекта
		return eSides::None;
	}

	sf::FloatRect GField::_getActiveRange(sf::Vector2f gameSize) {
		auto size = gameSize * 1.f;
		auto coords = m_player->getPosition() - size / 2.f;

		return sf::FloatRect(coords, size);
	}

	void GField::gameOver() {
		m_gameOver = true;
	}

	bool GField::checkWon() {
		if (m_pointsCount <= 0) m_isWon = true;

		return m_isWon;
	}

	bool GField::checkGameOver() {
		return m_gameOver;
	}

	void GField::setPlayer(Actor* player) {
		m_player = player;

		m_player->setOnDead([&] {
			gameOver();
		});
	}

	Actor* GField::getPlayer() {
		return m_player;
	}

	GField::~GField() {

	}

} // namespace pg