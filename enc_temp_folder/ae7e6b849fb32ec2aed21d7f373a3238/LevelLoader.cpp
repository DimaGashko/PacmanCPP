#include "LevelLoader.hpp"

namespace pg {

	LevelLoader::LevelLoader() {

	}

	LevelLoader::Level LevelLoader::loadFromTmx(std::string url) {
		tinyxml2::XMLDocument xmlLevel;
		auto status = xmlLevel.LoadFile(url.c_str());

		if (status != tinyxml2::XMLError::XML_SUCCESS) {
			std::cerr << "Can't load level" << std::endl;
			return _getDefLevel();
		}

		Level result;

		auto xmlMap = xmlLevel.FirstChildElement("map");
		auto xmlTileset = xmlMap->FirstChildElement("tileset");

		std::string csvGids = xmlMap->FirstChildElement("layer")
			->FirstChildElement("data")->GetText();

		std::vector<int> gids = _parseCsvGids(csvGids);
		
		sf::Vector2i size(
			atoi(xmlMap->Attribute("widht")),
			atoi(xmlMap->Attribute("height"))
		);
		
		sf::Vector2i tileSize(
			atoi(xmlMap->Attribute("tilewidth")),
			atoi(xmlMap->Attribute("tileheight"))
		);

		std::cout << size.x << ":" << size.y << std::endl;
		std::cout << tileSize.x << ":" << tileSize.y << std::endl;
		std::cout << csvGids << std::endl;
		for (auto gid : gids) std::cout << gid << " ";

		return _getDefLevel();
	}

	LevelLoader::Level LevelLoader::loadFromTxt(std::string url) {
		std::ifstream fin(url);

		if (!fin) {
			std::cerr << "Can't load level" << std::endl;
			return _getDefLevel();
		}

		Level result;

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

					result.player = packman;
				}
			}

			height++;
		}

		size.x = width;
		size.y = height;

		auto gameField = new GameField(size, tileSize);
		gameField->addAllObjects(objects);

		result.gameField = gameField;
		return result;
	}

	LevelLoader::Level LevelLoader::_getDefLevel() {
		Level result;

		result.gameField = new GameField();
		result.player = NULL;

		return result;
	}

	std::vector<int> LevelLoader::_parseCsvGids(const std::string & str) {
		std::vector<int> result;
		std::istringstream iss(str);

		for (std::string s; iss >> s;) {
			result.push_back(atoi(s.c_str()));
		}

		return result;
	}

	LevelLoader::~LevelLoader() {

	}

} // namespace pg
