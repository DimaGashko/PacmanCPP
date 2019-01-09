#pragma once

#include <unordered_map>
#include <string>

#include <SFML/Audio.hpp>

namespace pg {

	class SoundManager {
	public:
		SoundManager();

		// Возвращает SoundыSource по пути к нему
		// Если звук ранее не добавлялся
		// То сначала добавляется через get
		sf::SoundSource* get(std::string url);

		// Добавляет звук в SoundManager
		bool add(std::string url);

		~SoundManager();

	private:

		// unordered_map добавленных звуков (так же является кэшем)
		// (не static, так как в этом случае при вызове 
		// Деструктора придется удалять все звуки, а они 
		// В этом рвемя могут использоваться в других экземплярах)
		std::unordered_map<std::string, sf::Sound*> m_sounds;


	};

}; // namespace pg
