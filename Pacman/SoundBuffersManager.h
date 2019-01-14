#pragma once

#include <string>
#include <unordered_map>

#include <SFML/Audio.hpp>

namespace pg {

	class SoundBuffersManager {
	public:
		SoundBuffersManager();

		bool add(std::string url);

		sf::SoundBuffer get(std::string url);

		void remove(std::string url);

		bool has(std::string url);
		
		std::unordered_map<std::string, sf::SoundBuffer> m_buffers;

		~SoundBuffersManager();
	};

}; // namespace pg

