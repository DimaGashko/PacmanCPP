#include "AnimationManager.hpp"

namespace pg {

	AnimationManager::AnimationManager(
		sf::Shape *shape,
		sf::Texture &texture,
		std::vector<std::string> &names,
		std::vector<std::vector<sf::IntRect>> &frames,
		std::vector<std::vector<int>> &durations
	) :
		m_texture(texture)
	{
		for (auto i = 0; i < names.size(); i++) {
			m_animations[names[i]] = new pg::Animation(
				shape, texture, frames[i], durations[i]
			);
		
		}
	}

	void AnimationManager::update(int renderFrameTime) {
		m_animations[m_currectAnimation]->update(renderFrameTime);
	}
	 
	void AnimationManager::play() {
		m_animations[m_currectAnimation]->play();
	}

	void AnimationManager::pause() {
		m_animations[m_currectAnimation]->pause();
	}

	AnimationManager::~AnimationManager() {
		m_animations.clear();
	}

}