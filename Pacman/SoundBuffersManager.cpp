#include "SoundBuffersManager.h"

namespace pg {

	SoundBuffersManager::SoundBuffersManager() {

	}


	SoundBuffersManager::~SoundBuffersManager() {
		m_buffers.clean();
	}

}; // namespace pg