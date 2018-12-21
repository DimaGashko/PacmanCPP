#include "LevelLoader.hpp"

namespace pg {

	LevelLoader::LevelLoader() {

	}

	GameField* LevelLoader::loadFromTxt(std::string url) {
		std::ifstream fin(url);
		
		if (!fin) {
			return new GameField();
		}

		std::vector<GameObject*> objects;
	    sf::Vector2i tileSize(16, 16);
		sf::Vector2i size(0, 0);

		std::string row;
		int width = 0, height = 0;
		
		while (std::getline(fin, row)) {
			width = row.length();
			int y = height;

			for (int x = 0; x < width; x++) {
				char key = row[x];
				sf::Vector2f realCoords(x * tileSize.x, y * tileSize.y);

				if (key == '#') {
					objects.push_back(new GameObject(realCoords));
				} 
				else if (key == 'p') {
					auto packman = new GameObject(realCoords);
					objects.push_back(packman);
				}
			}

			height++;
		}

		size.x = width;
		size.y = height;
		
		auto gameField = new GameField(size, tileSize);
		gameField->addAllObjects(objects);

		return gameField;
	}

	


	LevelLoader::~LevelLoader() {

	}

} // namespace pg
