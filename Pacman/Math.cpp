#include "Math.hpp"

namespace pg {

	

	inline bool Math::intersectsNormalRect() {
		return false;
	}

	inline bool Math::intersectsL2() {
		return false;
	}

	inline bool Math::intersectsL1(float a1, float a2, float b1, float b2) {
		return (a1 < b1) ? (b1 < a2) : (a1 < b2);
	}

}; // namespace pg