#include "SoundManager.hpp"

namespace pg {

	SoundManager::SoundManager() {
	
	}

	sf::Sound SoundManager::get(std::string url) {
		add(url);

		return sf::Sound(*m_soundBuffers[url]);
	}

	bool SoundManager::add(std::string url) {
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