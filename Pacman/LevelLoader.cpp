#include "LevelLoader.hpp"

namespace pg {

	LevelLoader::LevelLoader() {

	}

	GameField* LevelLoader::loadFromTmx(std::string url) {
		tinyxml2::XMLDocument xmlTileset;
		tinyxml2::XMLDocument xmlLevel;

		auto status = xmlLevel.LoadFile(url.c_str());

		if (status != tinyxml2::XMLError::XML_SUCCESS) {
			std::cerr << "Can't load the level" << std::endl;
			return new GameField();
		}
		
		_LevelConfig levelConfig = _parseXmlLevel(xmlLevel);
		
		status = xmlTileset.LoadFile(levelConfig.tilesetUrl.c_str());

		if (status != tinyxml2::XMLError::XML_SUCCESS) {
			std::cerr << "Can't load the tileset" << std::endl;
			return new GameField();
		}
		
		_TilesetConfig tilesetConfig = _parseXmlTileset(xmlTileset);
		
		return _creatLevel(levelConfig, tilesetConfig);
	}

	GameField* LevelLoader::_creatLevel(_LevelConfig levelConfig, _TilesetConfig tilesetConfig) {
		auto size = levelConfig.size;
		auto tileSize = levelConfig.tileSize;

		GameField* gameField = new GameField(size, tileSize);

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
					gameField->addObject(obj);
					continue;
				}

				_TileConfig tileConfig = tilesetConfig.tiles[id];
				auto type = tileConfig.type;
				GameObject *obj;

				if (type == "Wall") {
					obj = new Wall(texture);
				}
				else if (type == "Point") {
					obj = new Point(texture);
				}
				else if (type == "Pacman") {
					Pacman *pacman = new Pacman(texture);

					gameField->setPlayer(pacman);
					obj = pacman;
				}
				else {
					obj = new GameObject(texture);
				}

				obj->setPosition(coords);
				obj->setSize(sf::Vector2f(tileSize));

				gameField->addObject(obj);
			}
		}

		return gameField;
	}

	GameField* LevelLoader::loadFromTxt(std::string url) {
		std::ifstream fin(url);

		if (!fin) {
			std::cerr << "Can't load level" << std::endl;
			return new GameField();
		}

		Actor *player = nullptr;

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
					obj = new Wall();
				}
				else if (key == 'p') {
					Pacman *pacman = new Pacman();
					player = pacman;

					obj = pacman;
				}
				else {
					obj = new Wall();
				}

				obj->setSize(sf::Vector2f(16, 16));
				obj->setPosition(realCoords);
				objects.push_back(obj);
			}

			height++;
		}

		size.x = width;
		size.y = height;

		auto gameField = new GameField(size, tileSize);
		gameField->addAllObjects(objects);
		gameField->setPlayer(player);

		return gameField;
	}

	LevelLoader::_LevelConfig LevelLoader::_parseXmlLevel(tinyxml2::XMLDocument &xmlLevel) {
		_LevelConfig config;

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

	LevelLoader::_TilesetConfig LevelLoader::_parseXmlTileset(tinyxml2::XMLDocument &xmlTilesetDoc) {
		_TilesetConfig config;

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
			_TileConfig tileConfig;
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
