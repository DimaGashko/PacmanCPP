#pragma once

#include <unordered_map>

#include <SFML/Audio.hpp>

namespace pg {

	class SoundManager {
	public:
		SoundManager();
		~SoundManager();

	private:

		static std::unordered_map<std::string, sf::SoundSource*> s_sounds;
	};

}; // namespace pg
