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

		unsigned short maxFps = 300;

		void initWindow();
		void draw();
	};

} // namespace pg

