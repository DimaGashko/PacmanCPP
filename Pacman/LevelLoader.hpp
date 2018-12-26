#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

#include "lib/tinyxml2.h"

#include "GameField.hpp"
#include "GameObject.hpp"
#include "Wall.hpp"
#include "Point.hpp"
#include "Pacman.hpp"
#include "Blinky.hpp"
#include "Pinky.hpp"
#include "Inky.hpp"
#include "Clyde.hpp"

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

		struct _TileConfig {
			std::string type;
			
			std::vector<std::string> propertyNames;
			std::vector<std::string> propertyTypes;
			std::vector<std::string> propetryValues;

			std::vector<int> animationFrameIds;
			std::vector<int> animationDurations;
		};

		struct _TilesetConfig {
			int columns;
			sf::Vector2i tileSize;
			sf::Texture *tilesetTexture;

			std::unordered_map<int, _TileConfig> tiles;

			std::unordered_map<std::string, std::vector<std::string>> animationNames;
			std::unordered_map<std::string, std::vector<std::vector<sf::IntRect>>> animationFrames;
			std::unordered_map<std::string, std::vector<std::vector<int>>> animationDurations;
		};

		_TilesetConfig *m_tilesetConfig;

		void loadTileset();
		void createAnimationConfigs();
		void parseTiles(tinyxml2::XMLElement *xmlTileset);

		GameField* _creatLevel(_LevelConfig levelConfig);
		_LevelConfig _parseXmlLevel(tinyxml2::XMLDocument &xmlLevel);
	
		sf::IntRect _getTextureRectByTileId(int id);

		static constexpr char TILESET_URL[] = "configs/tilesets/tileset.tsx";
	};

} // namespace pg
