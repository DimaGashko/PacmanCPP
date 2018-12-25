#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include <string>

#include "Animation.hpp"

namespace pg {

	class AnimationManager {

	public:
		AnimationManager();

		AnimationManager(
			sf::RectangleShape *shape,
			sf::Texture *texture,
			std::vector<std::string> &names,
			std::vector<std::vector<sf::IntRect>> &frames,
			std::vector<std::vector<int>> &durations
		);

		void update(int renderFrameTime);

		bool set(std::string animationName);

		void play();
		void pause();

		~AnimationManager();

	private:
		sf::Texture *m_texture;

		pg::Animation *m_currectAnimation;
		std::string m_currentAnimationName;

		std::unordered_map<std::string, pg::Animation*> m_animations;

	};

}

