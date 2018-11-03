#pragma once

#include "GWindow.h"

namespace pg {

	class PacmanGame {
	public:
		PacmanGame();
		void init();
		~PacmanGame();
	private:
		GWindow gWindow;
	};

} //namespace pg
