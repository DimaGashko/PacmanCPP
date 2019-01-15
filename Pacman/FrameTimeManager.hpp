#pragma once

#include "SFML/Graphics.hpp"

namespace pg {

	class FrameTimeManager {
	public:
		FrameTimeManager();

		// Сообщает об наступлении нового карда
		// Метод нужно вызывать на каждом кадре
		void update();

		// Возврвщает время кадра
		int get();

		~FrameTimeManager();

	private:
		sf::Clock m_clock;

		int m_frameTime;
	};

}; // namespace pg

