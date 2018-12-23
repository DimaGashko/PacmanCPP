#pragma once

namespace pg {

	class Math {
	public:

		// Пересекаются ли прямоугольники 
		// (со сторонами паралельными осям)
		static bool intersectsNormalRect();

		// Пересекаются ли 2-мерные отрезки
		static bool intersectsL2();

		// Пересекаются ли 1-мерные отрезки (a1; a2), (b1; b2)
		// Косание не считается пересечением
		// Параметры должны удовлетворять неравенству: a1 < a2 && b1 < b2
		static bool intersectsL1(float a1, float a2, float b1, float b2);
	};

}; // namespace pg


