#include "SoundManager.hpp"

namespace pg {

	SoundManager::SoundManager() {
	
	}

	sf::SoundSource* SoundManager::get(std::string url) {
		if (!m_sounds[url]) {
			add(url);

			if (!m_sounds[url]) {
				return nullptr;
			}
		
		}

		return m_sounds[url];

	}

	bool SoundManager::add(std::string url) {
		sf::SoundBuffer buffer;

		if (!buffer.loadFromFile(url)) {
			return false;
		}
		
		sf::Sound *sound;
		sound->setBuffer(buffer);

		m_sounds[url] = sound;

		return true;
	}

	


	SoundManager::~SoundManager() {
		m_sounds.clear();
	}

}; // namespace pg