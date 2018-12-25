#include "Animation.hpp"

namespace pg {

	Animation::Animation(
		sf::Shape *shape,
		sf::Texture &texture,
		std::vector<sf::IntRect> &frames,
		std::vector<int> &times
	) :
		m_shape(shape),
		m_texture(texture),
		m_frames(frames),
		m_times(times)
	{
		
	}

	void update(int time) {
		
	}

	Animation::~Animation() {

	}

}