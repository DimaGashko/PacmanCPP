#include "Point.hpp"

namespace pg {

	Point::Point() : Bonus() {

	}

	void Point::use(pg::GObject *obj) {
		if (!canItUseTheBonus(obj)) return;

		die();
	}

	bool Point::canItUseTheBonus(pg::GObject *obj) {
		if (dynamic_cast<Pacman*>(obj) != nullptr) return true;
		return false;
	}

	Point::~Point() {

	}

} // namespace pg