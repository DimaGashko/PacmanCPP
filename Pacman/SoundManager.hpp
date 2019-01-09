#pragma once

#include <unordered_map>
#include <string>

#include <SFML/Audio.hpp>

namespace pg {

	class SoundManager {
	public:
		SoundManager();

		enum Type {Sound, Music};

		// Возвращает SoundыSource по пути к нему
		// Если звук ранее не добавлялся
		// То сначала добавляется через get
		sf::SoundSource* get(std::string url);

		// Добавляет звук в SoundыManager
		bool add(std::string url, Type type = Type::Sound);

		~SoundManager();

	private:
		static std::unordered_map<std::string, sf::SoundSource*> s_sounds;


	};

}; // namespace pg
