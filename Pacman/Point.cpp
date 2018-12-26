#include "Point.hpp"

namespace pg {

	Point::Point() : Bonus() {

	}

	void Point::use(pg::GameObject *obj) {
		die();
		std::cout << "Point Use ";
	}

	Point::~Point() {

	}

} // namespace pg