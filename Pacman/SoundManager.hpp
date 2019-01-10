#pragma once

#include <unordered_map>
#include <string>

#include <SFML/Audio.hpp>

namespace pg {

	class SoundManager {
	public:
		SoundManager();

		// Возвращает SoundBuffer по пути к нему
		// Если звук ранее не добавлялся
		// То сначала добавляется через addBuffer
		sf::SoundBuffer* getBuffer(std::string url);

		// Добавляет SoundBuffer в SoundManager
		bool addBuffer(std::string url);

		~SoundManager();

	private:

		// unordered_map добавленных звуков
		// (не static, так как в этом случае при вызове 
		// Деструктора придется удалять все звуки, а они 
		// В этом рвемя могут использоваться в других экземплярах)
		std::unordered_map<std::string, sf::SoundBuffer*> m_soundBuffers;


	};

}; // namespace pg
