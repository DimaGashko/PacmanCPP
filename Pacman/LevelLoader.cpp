#include "LevelLoader.hpp"

namespace pg {

	LevelLoader::LevelLoader() {

	}

	LevelLoader::Level LevelLoader::loadFromTmx(std::string url) {
		tinyxml2::XMLDocument xmlTileset;
		tinyxml2::XMLDocument xmlLevel;

		auto status = xmlLevel.LoadFile(url.c_str());

		if (status != tinyxml2::XMLError::XML_SUCCESS) {
			std::cerr << "Can't load the level" << std::endl;
			return _getDefLevel();
		}
		
		LevelConfig levelConfig = _parseXmlLevel(xmlLevel);
		
		status = xmlTileset.LoadFile(levelConfig.tilesetUrl.c_str());

		if (status != tinyxml2::XMLError::XML_SUCCESS) {
			std::cerr << "Can't load the tileset" << std::endl;
			return _getDefLevel();
		}
		
		TilesetConfig tilesetConfig = _parseXmlTileset(xmlTileset);
		Level result;
		
		std::cout << tilesetConfig.columns << std::endl;
		

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

	LevelLoader::LevelConfig LevelLoader::_parseXmlLevel(tinyxml2::XMLDocument &xmlLevel) {
		LevelConfig config;

		auto xmlMap = xmlLevel.FirstChildElement("map");
		auto xmlTileset = xmlMap->FirstChildElement("tileset");

		auto xmlGids = xmlMap->FirstChildElement("layer")
			->FirstChildElement("data");

		config.size = sf::Vector2i(
			xmlMap->IntAttribute("width"),
			xmlMap->IntAttribute("height")
		);

		config.tileSize = sf::Vector2i(
			xmlMap->IntAttribute("tilewidth"),
			xmlMap->IntAttribute("tileheight")
		);

		std::string tilesetUrl = xmlTileset->Attribute("source");
		config.tilesetUrl = "configs/" + tilesetUrl.substr(3);

		auto xmlNextGid = xmlGids->FirstChildElement("tile");

		while (xmlNextGid != NULL) {
			config.gids.push_back(xmlNextGid->IntAttribute("gid"));
			xmlNextGid = xmlNextGid->NextSiblingElement("tile");
		}

		return config;
	}

	LevelLoader::TilesetConfig LevelLoader::_parseXmlTileset(tinyxml2::XMLDocument &xmlTileset) {
		TilesetConfig config;

		auto xmlTilesetElem = xmlTileset.FirstChildElement("tileset");

		config.columns = xmlTilesetElem->IntAttribute("columns");
		
		std::string imgUrl = xmlTilesetElem->FirstChildElement("image")->Attribute("source");
		imgUrl = imgUrl.substr(6);

		config.tileset = sf::Image();

		if (!config.tileset.loadFromFile(imgUrl)) {
			std::cerr << "Cant't load the tileset image";
		};

		return config;
	}

	LevelLoader::~LevelLoader() {

	}

} // namespace pg
