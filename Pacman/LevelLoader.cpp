#include "LevelLoader.hpp"

namespace pg {

	LevelLoader::LevelLoader() {

	}

	GameField* LevelLoader::loadFromTxt(std::string url) {
		std::ifstream fin(url);
		
		if (!fin) {
			return new GameField();
		}

		std::string row;
		
		while (std::getline(fin, row)) {
			std::cout << row << std::endl;
		}
	}

	


	LevelLoader::~LevelLoader() {

	}

} // namespace pg
