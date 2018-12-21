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
		
		return _creatLevel(levelConfig, tilesetConfig);
	}

	LevelLoader::Level LevelLoader::_creatLevel(LevelConfig levelConfig, TilesetConfig tilesetConfig) {
		Level result;

		auto size = levelConfig.size;
		auto tileSize = levelConfig.tileSize;

		result.gameField = new GameField(size, tileSize);

		for (int x = 0; x < size.x; x++) {
			for (int y = 0; y < size.y; y++) {
				int id = levelConfig.gids[y * size.x + x] - 1;

				sf::Vector2f coords(float(x * tileSize.x), float(y * tileSize.y));

				sf::Texture *texture = new sf::Texture;
				sf::IntRect textureArea(
					(id % tilesetConfig.columns) * tileSize.x, 
					(id / tilesetConfig.columns) * tileSize.y,
					levelConfig.tileSize.x, levelConfig.tileSize.y
				);

				texture->loadFromImage(tilesetConfig.tileset, textureArea);

				if (tilesetConfig.tiles.count(id) == 0) {
					GameObject *obj = new GameObject(texture);
					result.gameField->addObject(obj);
					continue;
				}

				TileConfig tileConfig = tilesetConfig.tiles[id];
				auto type = tileConfig.type;
				GameObject *obj;

				if (type == "Wall") {
					obj = new GameObject(texture);
				}
				else if (type == "Point") {
					obj = new GameObject(texture);
				}
				else if (type == "Pacman") {
					obj = new GameObject(texture);
					result.player = obj;
				}
				else {
					obj = new GameObject(texture);
				}

				obj->setPosition(coords);
				result.gameField->addObject(obj);
			}
		}

		return result;
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
			width = (int)row.length();
			int y = height;

			for (int x = 0; x < width; x++) {
				char key = row[x];
				sf::Vector2f realCoords(float(x * tileSize.x), float(y * tileSize.y));
				GameObject *obj;

				if (key == '#') {
					obj = new GameObject();
				}
				else if (key == 'p') {
					obj = new GameObject();

					result.player = obj;
				}
				else {
					obj = new GameObject();
				}

				obj->setPosition(realCoords);
				objects.push_back(obj);
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

	LevelLoader::TilesetConfig LevelLoader::_parseXmlTileset(tinyxml2::XMLDocument &xmlTilesetDoc) {
		TilesetConfig config;

		auto xmlTileset = xmlTilesetDoc.FirstChildElement("tileset");

		config.columns = xmlTileset->IntAttribute("columns");
		
		std::string imgUrl = xmlTileset->FirstChildElement("image")->Attribute("source");
		imgUrl = imgUrl.substr(6);

		config.tileset = sf::Image();

		if (!config.tileset.loadFromFile(imgUrl)) {
			std::cerr << "Cant't load the tileset image";
		};

		auto nextTile = xmlTileset->FirstChildElement("tile");

		while (nextTile) {
			TileConfig tileConfig;
			tileConfig.type = nextTile->Attribute("type");

			int id = nextTile->IntAttribute("id");
			config.tiles[id] = tileConfig;

			nextTile = nextTile->NextSiblingElement();
		}

		return config;
	}

	LevelLoader::~LevelLoader() {

	}

} // namespace pg
