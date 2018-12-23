#pragma once

#include <SFML/Graphics.hpp>

namespace pg {

	class Math {
	public:

		// ѕересекаютс€ ли пр€моугольники (со сторонами паралельными ос€м)
		// ѕереданные координаты должны быть последовательными (ax1 < ax2, by1 < by2...)
		static bool intersectsNormalRect(
			float ax1, float ay1, float ax2, float ay2,
			float bx1, float by1, float bx2, float by2
		);

		// ѕересекаютс€ ли 2-мерные отрезки
		static bool intersectsL2(sf::Vector2f start1, sf::Vector2f end1, sf::Vector2f start2, sf::Vector2f end2);

		// ѕересекаютс€ ли 1-мерные отрезки (a1; a2), (b1; b2)
		//  осание не считаетс€ пересечением
		// ѕараметры должны удовлетвор€ть неравенству: a1 < a2 && b1 < b2
		static bool intersectsL1(float a1, float a2, float b1, float b2);
	};

}; // namespace pg


