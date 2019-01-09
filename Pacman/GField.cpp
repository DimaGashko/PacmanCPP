#include "GField.hpp"

namespace pg {

	GField::GField()
	{

	}

	GField::GField(sf::Vector2i size, sf::Vector2i cellSize) :
		m_grid(size, cellSize)
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

		m_grid.add(object);

	}

	void GField::draw(sf::RenderWindow &window, sf::FloatRect visibleRange) {
		std::vector<GObject*> visibleObjects;
		m_grid.getObjectsOfRange(visibleRange, visibleObjects);

		for (auto &obj : visibleObjects) {
			obj->draw(window);
		}
	}

	void GField::update(sf::Vector2f gameSize, int frameTime) {
		m_collisionManager.update(m_grid, _getActiveRange(gameSize), frameTime);
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

	sf::FloatRect GField::_getActiveRange(sf::Vector2f gameSize) {
		auto size = gameSize * 1.f;
		auto coords = m_player->getPosition() - size / 2.f;

		return sf::FloatRect(coords, size);
	}

	GField::~GField() {

	}

} // namespace pg