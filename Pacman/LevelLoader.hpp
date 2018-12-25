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
		struct _LevelConfig {
			sf::Vector2i size;
			std::vector<std::vector<int>> gids;
			std::string tilesetUrl;
		};

		struct _TilesetConfig {
			int columns;
			sf::Vector2i tileSize;
			sf::Texture tilesetTexture;

			std::unordered_map<int, std::string> tileTypes;
			
			std::vector<std::string> animationNames;
			std::vector<std::vector<sf::IntRect>> animationFrames;
			std::vector<std::vector<int>> animationsTimes;

		};

		_TilesetConfig *m_tilesetConfig;

		void loadTileset();
		void parseTiles(tinyxml2::XMLElement *xmlTileset);

		GameField* _creatLevel(_LevelConfig levelConfig);
		_LevelConfig _parseXmlLevel(tinyxml2::XMLDocument &xmlLevel);
		_TilesetConfig* _parseXmlTileset(tinyxml2::XMLDocument &xmlTilesetDoc);

		sf::Texture* _getTexture(int gid, int id);
	
		static constexpr char TILESET_URL[] = "configs/tilesets/tileset.tsx";
	};

} // namespace pg
