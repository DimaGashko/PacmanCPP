#pragma once

#include <SFML/Graphics.hpp>

namespace pg {

	class Animation	{

	public:
		Animation(
			sf::Shape *shape, 
			sf::Texture &texture, 
			std::vector<sf::IntRect> &frames, 
			std::vector<int> &times
		);

		void update(int frameTime);
		
		~Animation();

	private:

		sf::Shape *m_shape;
		sf::Texture m_texture;
		std::vector<sf::IntRect> m_frames;
		std::vector<int> m_times;

	};

}

