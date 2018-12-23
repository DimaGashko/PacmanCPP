#include "Math.hpp"

namespace pg {

	inline bool Math::intersectsNormalRect(
		float ax1, float ay1, float ax2, float ay2,
		float bx1, float by1, float bx2, float by2
	) {
		return Math::intersectsL1(ax1, ax2, bx1, bx2) &&
			Math::intersectsL1(ay1, ay2, by1, by2);
	}

	inline bool Math::intersectsL1(float a1, float a2, float b1, float b2) {
		return (a1 < b1) ? (b1 < a2) : (a1 < b2);
	}

	bool Math::intersectsL2(sf::Vector2f start1, sf::Vector2f end1, sf::Vector2f start2, sf::Vector2f end2) {
		sf::Vector2f dir1 = end1 - start1;
		sf::Vector2f dir2 = end2 - start2;

		// Cчитаем уравнения прямых проходящих через отрезки
		float a1 = -dir1.y;
		float b1 = +dir1.x;
		float d1 = -(a1*start1.x + b1 * start1.y);

		float a2 = -dir2.y;
		float b2 = +dir2.x;
		float d2 = -(a2*start2.x + b2 * start2.y);

		// Подставляем концы отрезков, для выяснения в каких полуплоскотях они
		float seg1Line2Start = a2 * start1.x + b2 * start1.y + d2;
		float seg1Line2End = a2 * end1.x + b2 * end1.y + d2;

		float seg2Line1Start = a1 * start2.x + b1 * start2.y + d1;
		float seg2Line1End = a1 * end2.x + b1 * end2.y + d1;

		// Если концы одного отрезка имеют один знак, значит он в одной полуплоскости и пересечения нет.
		if (seg1Line2Start * seg1Line2End >= 0 || seg2Line1Start * seg2Line1End >= 0)
			return false;

		return true;
	}

}; // namespace pg