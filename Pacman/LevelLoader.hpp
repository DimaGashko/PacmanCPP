#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

#include "lib/tinyxml2.h"

#include "GameObject.hpp"
#include "GameField.hpp"

namespace pg {

	class LevelLoader {

	public:
		LevelLoader();

		struct Level {
			GameField *gameField = NULL;
			GameObject *player = NULL;
		};

		Level loadFromTxt(std::string url);
		Level loadFromTmx(std::string url);

		~LevelLoader();

	private:
		struct LevelConfig {
			sf::Vector2i size, tileSize;
			std::vector<int> gids;
			std::string tilesetUrl;
		};

		struct TileConfig {
			std::string type;
		};

		struct TilesetConfig {
			sf::Image tileset;
			int columns;
			std::unordered_map<int, TileConfig> tiles;
		};

		Level _getDefLevel();
		Level _creatLevel(LevelConfig levelConfig, TilesetConfig tilesetConfig);
		LevelConfig _parseXmlLevel(tinyxml2::XMLDocument &xmlLevel);
		TilesetConfig _parseXmlTileset(tinyxml2::XMLDocument &xmlTilesetDoc);
	};

} // namespace pg
