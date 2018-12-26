#include "Animation.hpp"

namespace pg {

	Animation::Animation(
		sf::Shape *shape,
		sf::Texture *texture,
		std::vector<sf::IntRect> &frames,
		std::vector<int> &durations
	) :
		m_shape(shape),
		m_texture(texture),
		m_frames(frames),
		m_durations(durations)
	{
		m_shape->setTexture(m_texture);
	}

	void Animation::update(int renderFrameTime) {
		if (!m_playing) return;
		auto size = m_frames.size();

		if (size == 0) return;

		m_timeToFrameChange -= renderFrameTime;
		if (m_timeToFrameChange > 0) return;

		m_currentFrame = (m_currentFrame + 1) % size;
		
		m_timeToFrameChange = m_durations[m_currentFrame];
		m_shape->setTextureRect(m_frames[m_currentFrame]);
	}

	void Animation::play() {
		m_playing = true;
	}

	void Animation::pause() {
		m_playing = false;
	}

	void Animation::reset() {
		m_playing = false;
		m_currentFrame = -1;
		m_timeToFrameChange = 0;
	}

	Animation::~Animation() {

	}

}