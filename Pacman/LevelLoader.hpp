#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

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
		Level _getDefLevel();

		std::vector<int> _parseCsvGids(const std::string &str);
	};

} // namespace pg