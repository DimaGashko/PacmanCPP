#include "SoundManager.hpp"

namespace pg {

	SoundManager::SoundManager() {
	
	}

	sf::SoundBuffer* SoundManager::getBuffer(std::string url) {
		addBuffer(url);

		return m_soundBuffers[url];
	}

	bool SoundManager::addBuffer(std::string url) {
		if (m_soundBuffers[url]) return true;

		sf::SoundBuffer *buffer = new sf::SoundBuffer();

		if (!buffer->loadFromFile(url)) {
			return false;
		}

		m_soundBuffers[url] = buffer;

		return true;
	}

	SoundManager::~SoundManager() {
		m_soundBuffers.clear();
	}

}; // namespace pg