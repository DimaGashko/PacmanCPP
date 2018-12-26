#include "Point.hpp"

namespace pg {

	Point::Point() : Bonus() {

	}

	void Point::use(pg::GameObject *obj) {
		die();
		std::cout << "Point Use ";
	}

	bool Point::itCanUseTheBonus(pg::GameObject *obj) {
		if (dynamic_cast<Pacman*>(obj) != nullptr) return true;
		return false;
	}

	Point::~Point() {

	}

} // namespace pg