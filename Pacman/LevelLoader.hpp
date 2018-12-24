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
#include "Point.hpp"

namespace pg {

	class LevelLoader {

	public:
		LevelLoader();
		
		GameField* loadFromTmx(std::string url);
		GameField* loadFromTxt(std::string url);
		
		~LevelLoader();

	private:
		// Текстуры тайлов (ключ - id тайла
		std::unordered_map<int, sf::Texture*> textures;

		struct _LevelConfig {
			sf::Vector2i size;
			std::vector<int> gids;
			std::string tilesetUrl;
		};

		struct _TileConfig {
			std::string type;
		};

		struct _TilesetConfig {
			int columns;
			sf::Vector2i tileSize;
			sf::Image tileset;
			std::unordered_map<int, _TileConfig> tiles;
		};

		GameField* _creatLevel(_LevelConfig levelConfig, _TilesetConfig tilesetConfig);
		_LevelConfig _parseXmlLevel(tinyxml2::XMLDocument &xmlLevel);
		_TilesetConfig _parseXmlTileset(tinyxml2::XMLDocument &xmlTilesetDoc);
	
		sf::Texture* _getTexture(_TilesetConfig tilesetConfig, int gid, int id);
	};

} // namespace pg
