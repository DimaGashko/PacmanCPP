#include "SoundManager.hpp"

namespace pg {

	SoundManager::SoundManager(SoundBuffersManager *buffers):
		m_buffers(buffers)
	{
	
	}

	void SoundManager::playOnce(std::string url) {
		auto sound = get(url);

		sound->setLoop(false);
		sound->play();
	}

	void SoundManager::playLoop(std::string url) {
		auto sound = get(url);

		sound->setLoop(true);
		sound->play();
	}

	void SoundManager::pause(std::string url) {
		auto sound = get(url);

		sound->pause();
	}

	bool SoundManager::add(std::string url) {
		if (m_sounds[url] != nullptr) return true;

		auto buffer = m_buffers->get(url);
		if (!buffer) return false;

		auto *sound = new sf::Sound(*buffer);

		m_sounds[url] = sound;

		return true;
	}

	sf::Sound* SoundManager::get(std::string url) {
		if (m_sounds[url] == nullptr) {
			add(url);
		}

		return m_sounds[url];
	}

	SoundManager::~SoundManager() {
		m_sounds.clear();
	}

}; // namespace pg