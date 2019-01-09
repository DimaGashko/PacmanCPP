#pragma once

#include "Grid.hpp"
#include "GObject.hpp"

namespace pg {

	class CollisionManager {
	public:
		CollisionManager();

		void update(Grid &grid, sf::FloatRect activeRange, int frameTime);

		~CollisionManager();
	private:

		enum _eSides { Left, Top, Right, Bottom, None };

		void proc(GObject *obj, GObject *withObj);

		// ¬озвращает сторону obj2, с которой столкнулс€ obj1
		_eSides _getCollisionSide(GObject *obj1, GObject *obj2);

	};

}; // nampespace pg