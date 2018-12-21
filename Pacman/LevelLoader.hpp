#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "GameObject.hpp"
#include "GameField.hpp"

namespace pg {

	struct Level {
		GameField *gameField;
		GameObject *player;
	};

	class LevelLoader {

	public:
		LevelLoader();

		Level loadFromTxt(std::string url);

		~LevelLoader();

	private:
	};

} // namespace pg
