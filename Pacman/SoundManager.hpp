#pragma once

#include <string>
#include <unordered_map>

#include <SFML/Audio.hpp>

namespace pg {

	class SoundManager {
	public:
		SoundManager();

		bool add(std::string url);

		void playOnce(std::string url);
		void playLoop(std::string url);

		void pause(std::string url);

		sf::SoundBuffer* get(std::string url);

		~SoundManager();

	private:

		std::unordered_map<std::string, sf::SoundBuffer*> m_soundâ;


	};

}; // namespace pg
