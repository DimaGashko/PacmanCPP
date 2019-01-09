#include "SoundManager.hpp"

namespace pg {

	SoundManager::SoundManager() {
	
	}

	sf::Sound* SoundManager::get(std::string url) {
		add(url);

		return m_sounds[url];
	}

	bool SoundManager::add(std::string url) {
		if (m_sounds[url]) return true;

		sf::SoundBuffer buffer;

		if (!buffer.loadFromFile(url)) {
			return false;
		}
		
		sf::Sound *sound = new sf::Sound();
		sound->setBuffer(buffer);

		m_sounds[url] = sound;

		return true;
	}

	


	SoundManager::~SoundManager() {
		m_sounds.clear();
	}

}; // namespace pg