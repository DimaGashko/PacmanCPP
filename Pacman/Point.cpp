#include "Point.hpp"

namespace pg {

	Point::Point() : Bonus() {

	}

	void Point::use(pg::GameObject *obj) {
		if (!canItUseTheBonus(obj)) return;

		die();
	}

	bool Point::canItUseTheBonus(pg::GameObject *obj) {
		if (dynamic_cast<Pacman*>(obj) != nullptr) return true;
		return false;
	}

	Point::~Point() {

	}

} // namespace pg