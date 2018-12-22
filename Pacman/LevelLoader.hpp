#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

#include "lib/tinyxml2.h"

#include "GameField.hpp"
#include "GameObject.hpp"
#include "Actor.hpp"
#include "Pacman.hpp"
#include "Wall.hpp"

namespace pg {

	class LevelLoader {

	public:
		LevelLoader();

		struct Level {
			GameField *gameField = NULL;
			Actor *player = NULL;
		};

		Level loadFromTxt(std::string url);
		Level loadFromTmx(std::string url);

		~LevelLoader();

	private:
		struct _LevelConfig {
			sf::Vector2i size, tileSize;
			std::vector<int> gids;
			std::string tilesetUrl;
		};

		struct _TileConfig {
			std::string type;
		};

		struct _TilesetConfig {
			sf::Image tileset;
			int columns;
			std::unordered_map<int, _TileConfig> tiles;
		};

		Level _getDefLevel();
		Level _creatLevel(_LevelConfig levelConfig, _TilesetConfig tilesetConfig);
		_LevelConfig _parseXmlLevel(tinyxml2::XMLDocument &xmlLevel);
		_TilesetConfig _parseXmlTileset(tinyxml2::XMLDocument &xmlTilesetDoc);
	};

} // namespace pg
