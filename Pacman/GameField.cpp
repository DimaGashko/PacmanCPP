#include "GameField.hpp"

namespace pg {

	GameField::GameField(sf::Vector2f size, sf::Vector2f cellSize, std::vector<GameObject> objects):
		m_size(size),
		m_cellSize(cellSize)
	{
		create(objects);
	}

	void GameField::create(std::vector<GameObject> objects) {
		
	}


	GameField::~GameField() {

	}

} // namespace pg