#include "SoundBuffersManager.h"

namespace pg {

	SoundBuffersManager::SoundBuffersManager() {

	}

	bool SoundBuffersManager::add(std::string url) {
		if (m_buffers[url] != nullptr) return true;

		auto *buffer = new sf::SoundBuffer();

		if (!buffer->loadFromFile(url)) {
			return false;
		}

		m_buffers[url] = buffer;
	}

	sf::SoundBuffer* SoundBuffersManager::get(std::string url) {
		if (m_buffers[url] == nullptr) {
			add(url);
		}

		return m_buffers[url];
	}

	bool SoundBuffersManager::has(std::string url) {
		return m_buffers[url] != nullptr;
	}

	SoundBuffersManager::~SoundBuffersManager() {
		m_buffers.clear();
	}

}; // namespace pg