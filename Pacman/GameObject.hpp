#pragma once

#include <SFML/Graphics.hpp>

namespace pg {

	class GameObject {
	public:
		GameObject();
		void interact();
		void move(float x, float y);
		virtual ~GameObject();
	private:
		void _setPrevCoords();

	};

} // namespace pg