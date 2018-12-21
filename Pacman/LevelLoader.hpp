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

		GameField* loadFromTxt(std::string url);

		~LevelLoader();

	private:
	};

} // namespace pg
