#include "Animation.hpp"

namespace pg {

	Animation::Animation(
		sf::Shape *shape,
		sf::Texture &texture,
		std::vector<sf::IntRect> &areas,
		std::vector<int> &times
	) :
		m_shape(shape),
		m_texture(texture),
		m_areas(areas),
		m_times(times)
	{
		
	}

	Animation::~Animation() {

	}

}