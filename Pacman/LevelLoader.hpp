#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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

		~LevelLoader();

	private:
	};

} // namespace pg
