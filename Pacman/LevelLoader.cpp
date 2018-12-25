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

					auto tile = m_tilesetConfig->tiles[id];
					auto type = tile.type;

					GameObject *obj;

					sf::Vector2f coords(float(x * tileSize.x), float(y * tileSize.y));

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
					obj->setSize(sf::Vector2f(tileSize));

					auto animNames = m_tilesetConfig->animationNames;
					bool hasAnim = animNames.find(type) != animNames.end();

					if (hasAnim && !animNames[type].empty()) {

						obj->setAnimations(
							m_tilesetConfig->tilesetTexture, animNames[type],
							m_tilesetConfig->animationFrames[type],
							m_tilesetConfig->animationDurations[type]
						);

					}
					else {

						obj->setTexture(
							m_tilesetConfig->tilesetTexture,
							_getTextureRectByTileId(id)
						);

					}

					gameField->addObject(obj);
				}
			}
		}

		return gameField;
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

		config->tilesetTexture = new sf::Texture();

		if (!config->tilesetTexture->loadFromFile(imgUrl)) {
			std::cerr << "Cant't load the tileset image";
		};

		parseTiles(xmlTileset);

		createAnimationConfigs();
	}
	
	void LevelLoader::parseTiles(tinyxml2::XMLElement *xmlTileset) {
		auto config = m_tilesetConfig;

		auto nextTile = xmlTileset->FirstChildElement("tile");

		while (nextTile) {
			_TileConfig tile;
			int id = nextTile->IntAttribute("id");

			auto type = nextTile->Attribute("type");
			tile.type = (type) ? type : "";

			auto xmlProperties = nextTile->FirstChildElement("properties");
			auto xmlAnimation = nextTile->FirstChildElement("animation");

			auto nextProperty = (xmlProperties) ?
				xmlProperties->FirstChildElement("property") : NULL;

			while (nextProperty != NULL) {	
				auto name = nextProperty->Attribute("name");
				auto type = nextProperty->Attribute("type");
				auto value = nextProperty->Attribute("value");

				tile.propertyNames.push_back(name ? name : "");
				tile.propetryValues.push_back(value ? value : "");
				tile.propertyTypes.push_back(type ? type : "string");

				nextProperty = nextProperty->NextSiblingElement("property");
			}

			auto nextFrame = (xmlAnimation) ?
				xmlAnimation->FirstChildElement("frame") : NULL;

			while (nextFrame != NULL) {

				auto tileid = nextFrame->IntAttribute("tileid");
				auto duration = nextFrame->IntAttribute("duration");

				tile.animationFrameIds.push_back(tileid);
				tile.animationDurations.push_back(duration);

				nextFrame = nextFrame->NextSiblingElement("frame");
			}

			config->tiles[id] = tile;
			nextTile = nextTile->NextSiblingElement("tile");
		}
	}

	void LevelLoader::createAnimationConfigs() {
		for (auto item : m_tilesetConfig->tiles) {
			auto tile = item.second;
			if (tile.type.empty()) continue;

			const std::string ANIMATION_PREFIX = "animation_";

			std::vector<std::string> names;
			std::vector<std::vector<sf::IntRect>> frames;
			std::vector<std::vector<int>> durations;

			for (int i = 0; i < tile.propertyNames.size(); i++) {
				auto name = tile.propertyNames[i];

				std::vector<int> _frameIds;
				std::vector<int> _durations;
				std::vector<sf::IntRect> _frames;

				if (name == "animationName") {
					names.push_back(tile.propetryValues[i]);

					_durations = tile.animationDurations;
					_frameIds = tile.animationFrameIds;
				}
				else if (name.rfind(ANIMATION_PREFIX, 0) == 0) {
					names.push_back(name.substr(ANIMATION_PREFIX.size()));

					auto animationTileId = atoi(tile.propetryValues[i].c_str());
					auto animationTile = m_tilesetConfig->tiles[animationTileId];

					_durations = animationTile.animationDurations;
					_frameIds = animationTile.animationFrameIds;
				}

				durations.push_back(_durations);

				for (auto frameId : _frameIds) {
					_frames.push_back(_getTextureRectByTileId(frameId));
				}

				frames.push_back(_frames);
			}

			m_tilesetConfig->animationNames[tile.type] = names;
			m_tilesetConfig->animationFrames[tile.type] = frames;
			m_tilesetConfig->animationDurations[tile.type] = durations;
		}
	}

	sf::IntRect LevelLoader::_getTextureRectByTileId(int tileid) {
		return sf::IntRect(
			(tileid % m_tilesetConfig->columns) * m_tilesetConfig->tileSize.x,
			(tileid / m_tilesetConfig->columns) * m_tilesetConfig->tileSize.y,
			m_tilesetConfig->tileSize.x, m_tilesetConfig->tileSize.y
		);
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
		delete m_tilesetConfig->tilesetTexture;
		delete m_tilesetConfig;
	} 

} // namespace pg
