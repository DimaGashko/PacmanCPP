#pragma once

namespace pg {

	class Math {
	public:

		// ������������ �� �������������� 
		// (�� ��������� ������������ ����)
		static bool intersectsNormalRect();

		// ������������ �� 2-������ �������
		static bool intersectsL2();

		// ������������ �� 1-������ ������� (a1; a2), (b1; b2)
		// ������� �� ��������� ������������
		// ��������� ������ ������������� �����������: a1 < a2 && b1 < b2
		static bool intersectsL1(float a1, float a2, float b1, float b2);
	};

}; // namespace pg


