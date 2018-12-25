#include "LevelLoader.hpp"

namespace pg {

	LevelLoader::LevelLoader() {

	}

	GameField* LevelLoader::loadFromTmx(std::string url) {
		if (!m_tilesetConfig) {
			loadTileset();
		}

		tinyxml2::XMLDocument xmlLevel;

		auto status = xmlLevel.LoadFile(url.c_str());

		if (status != tinyxml2::XMLError::XML_SUCCESS) {
			std::cerr << "Can't load the level" << std::endl;
		}
		
		_LevelConfig levelConfig = _parseXmlLevel(xmlLevel);
		
		return _creatLevel(levelConfig);
	}
	 
	GameField* LevelLoader::_creatLevel(_LevelConfig levelConfig) {
		auto size = levelConfig.size;
		auto tileSize = m_tilesetConfig->tileSize;

		GameField* gameField = new GameField(size, tileSize);

		for (auto gids : levelConfig.gids) {
			for (int x = 0; x < size.x; x++) {
				for (int y = 0; y < size.y; y++) {
					int gid = gids[y * size.x + x];
					if (gid == 0) continue;
					int id = gid - 1;

					sf::Vector2f coords(float(x * tileSize.x), float(y * tileSize.y));
					auto texture = _getTexture(gid, id);

					auto type = m_tilesetConfig->tileTypes[id];
					GameObject *obj;

					if (type == "Pacman") {
						Pacman *pacman = new Pacman();

						gameField->setPlayer(pacman);
						obj = pacman;
					}

					else if (type == "Ghost") obj = new GameObject();

					else if (type == "Wall") obj = new Wall();
					else if (type == "Point") obj = new Point();

					else obj = new GameObject();

					obj->setPosition(coords);
					obj->setTexture(texture);
					obj->setSize(sf::Vector2f(tileSize));

					gameField->addObject(obj);
				}
			}
		}

		return gameField;
	}

	sf::Texture* LevelLoader::_getTexture(int gid, int id) {
		if (m_textures[gid] == NULL) {
			sf::Texture *texture = new sf::Texture;

			sf::IntRect textureArea(
				(id % m_tilesetConfig->columns) * m_tilesetConfig->tileSize.x,
				(id / m_tilesetConfig->columns) * m_tilesetConfig->tileSize.y,
				m_tilesetConfig->tileSize.x, m_tilesetConfig->tileSize.y
			);

			texture->loadFromImage(m_tilesetConfig->tileset, textureArea);

			m_textures[gid] = texture;
		}

		return m_textures[gid];
	}

	LevelLoader::_LevelConfig LevelLoader::_parseXmlLevel(tinyxml2::XMLDocument &xmlLevel) {
		_LevelConfig config;

		auto xmlMap = xmlLevel.FirstChildElement("map");
		auto xmlTileset = xmlMap->FirstChildElement("tileset");

		config.size = sf::Vector2i(
			xmlMap->IntAttribute("width"),
			xmlMap->IntAttribute("height")
		);

		int gidsLen = config.size.x * config.size.y;

		std::string tilesetUrl = xmlTileset->Attribute("source");
		config.tilesetUrl = "configs/" + tilesetUrl.substr(3);
		
		auto xmlNextLayer = xmlMap->FirstChildElement("layer");

		while (xmlNextLayer != NULL) {
			std::vector<int> layerGids(gidsLen);
			
			auto xmlNextGid = xmlNextLayer->FirstChildElement("data")->FirstChildElement("tile");

			for (int i = 0; xmlNextGid != NULL; i++) {
				layerGids[i] = xmlNextGid->IntAttribute("gid");

				xmlNextGid = xmlNextGid->NextSiblingElement("tile");
			}

			config.gids.push_back(layerGids);
			xmlNextLayer = xmlNextLayer->NextSiblingElement("layer");
		}

		return config;
	}

	void LevelLoader::loadTileset() {
		tinyxml2::XMLDocument xmlTilesetDoc;
		auto status = xmlTilesetDoc.LoadFile(TILESET_URL);

		if (status != tinyxml2::XMLError::XML_SUCCESS) {
			std::cerr << "Can't load the tileset" << std::endl;
		}

		m_tilesetConfig = new _TilesetConfig;
		auto config = m_tilesetConfig;

		auto xmlTileset = xmlTilesetDoc.FirstChildElement("tileset");

		config->columns = xmlTileset->IntAttribute("columns");

		config->tileSize = sf::Vector2i(
			xmlTileset->IntAttribute("tilewidth"),
			xmlTileset->IntAttribute("tileheight")
		);

		std::string imgUrl = xmlTileset->FirstChildElement("image")->Attribute("source");
		imgUrl = imgUrl.substr(6);

		config->tilesetTexture = sf::Texture();

		if (!config->tilesetTexture.loadFromFile(imgUrl)) {
			std::cerr << "Cant't load the tileset image";
		};

		parseTiles(xmlTileset);
	}

	void LevelLoader::parseTiles(tinyxml2::XMLElement *xmlTileset) {
		auto config = m_tilesetConfig;

		auto nextTile = xmlTileset->FirstChildElement("tile");

		while (nextTile) {
			int id = nextTile->IntAttribute("id");
			auto type = nextTile->Attribute("type");

			config->tileTypes[id] = (type) ? type : "";

			nextTile = nextTile->NextSiblingElement();
		}
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
				GameObject *obj = nullptr;

				if (key == '#') {
					obj = new Wall();
				}
				else if (key == 'p') {
					Pacman *pacman = new Pacman();
					player = pacman;

					obj = pacman;
				}

				if (obj == nullptr) continue; 

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

	LevelLoader::~LevelLoader() {
		for (auto item : m_textures) {
			delete item.second;
		}

		m_textures.clear();

		delete m_tilesetConfig;
	} 

} // namespace pg
