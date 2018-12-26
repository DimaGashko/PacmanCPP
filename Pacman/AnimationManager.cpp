#include "AnimationManager.hpp"

namespace pg {

	AnimationManager::AnimationManager() {
		
	}

	AnimationManager::AnimationManager(
		sf::RectangleShape *shape,
		sf::Texture *texture,
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

	bool AnimationManager::set(std::string animationName) {
		if (m_currentAnimationName == animationName) return false;
		m_currentAnimationName = animationName;

		auto animate = m_animations[animationName];
		if (animate == NULL) return false;

		animate->reset();
		animate->play();

		m_currectAnimation = animate;

		return true;
	}

	void AnimationManager::update(int renderFrameTime) {
		if (!m_currectAnimation) return;
 		m_currectAnimation->update(renderFrameTime);
	}
	 
	void AnimationManager::play() {
		if (!m_currectAnimation) return;
		m_currectAnimation->play();
	}

	void AnimationManager::pause() {
		if (!m_currectAnimation) return;
		m_currectAnimation->pause();
	}

	AnimationManager::~AnimationManager() {
		m_animations.clear();
	}

}