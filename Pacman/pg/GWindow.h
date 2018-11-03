#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace pg {

	class GWindow {
	public:
		GWindow();
		void init();
		~GWindow();

	private:
		sf::RenderWindow window;
		std::string title;

		void initWindow();
	};

} // namespace pg

