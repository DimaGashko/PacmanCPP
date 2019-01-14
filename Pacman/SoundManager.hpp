#pragma once

#include <string>
#include <unordered_map>

#include <SFML/Audio.hpp>

#include "SoundBuffersManager.hpp"

namespace pg {

	class SoundManager {
	public:
		SoundManager(SoundBuffersManager *buffers);

		void playOnce(std::string url);
		void playLoop(std::string url);

		void pause(std::string url);

		bool add(std::string url);

		sf::Sound* get(std::string url);

		~SoundManager();

	private:

		std::unordered_map<std::string, sf::Sound*> m_sounds;

		SoundBuffersManager *m_buffers;

	};

}; // namespace pg
