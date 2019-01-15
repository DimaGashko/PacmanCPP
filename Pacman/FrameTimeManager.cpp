#include "FrameTimeManager.hpp"

namespace pg {

	FrameTimeManager::FrameTimeManager() {

	}

	void FrameTimeManager::update() {
		m_frameTime = m_clock.restart().asMilliseconds();

		if (m_frameTime > FrameTimeManager::MAX_FRAME_TIME) {
			m_frameTime = FrameTimeManager::MAX_FRAME_TIME;
		};
	}

	int FrameTimeManager::get() {
		return m_frameTime;
	}

	FrameTimeManager::~FrameTimeManager() {

	}

	const int FrameTimeManager::MAX_FRAME_TIME = 64; //Максимум 15 fps

}; // namespace pg