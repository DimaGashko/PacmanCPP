#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include <string>

#include "Animation.hpp"

namespace pg {

	class AnimationManager {

	public:
		AnimationManager(
			sf::Shape *shape,
			sf::Texture &texture,
			std::vector<std::string> &names,
			std::vector<std::vector<sf::IntRect>> &frames,
			std::vector<std::vector<int>> &times
		);

		void update(int renderFrameTime);

		void play();
		void pause();

		~AnimationManager();

	private:
		sf::Texture m_texture;

		std::string m_currectAnimation;
		std::unordered_map<std::string, pg::Animation*> m_animations;

	};

}

