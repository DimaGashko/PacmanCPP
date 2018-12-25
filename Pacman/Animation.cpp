#include "Animation.hpp"

namespace pg {

	Animation::Animation(sf::RectangleShape *rect, sf::Texture &texture) :
		m_rect(rect),
		m_texture(texture)
	{
	
	}

	Animation::~Animation() {

	}

}