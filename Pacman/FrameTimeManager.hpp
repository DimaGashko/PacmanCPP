#pragma once

#include "SFML/Graphics.hpp"

namespace pg {

	class FrameTimeManager {
	public:
		FrameTimeManager();

		// �������� �� ����������� ������ �����
		// ����� ����� �������� �� ������ �����
		void update();

		// ���������� ����� �����
		int get();

		~FrameTimeManager();

	private:
		sf::Clock m_clock;

		int m_frameTime;
	};

}; // namespace pg

