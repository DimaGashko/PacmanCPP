#pragma once

#include <vector>

#include "GameObject.hpp"

namespace pg {

	class GameField {
	public:
		GameField(sf::Vector2f size, sf::Vector2f cellSize, std::vector<GameObject> objects);
		
		~GameField();
	
	private:
		sf::Vector2f m_size;
		sf::Vector2f m_cellSize;

		void create(std::vector<GameObject> objects);
		
	};

} // namespace pg
