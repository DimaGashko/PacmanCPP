#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace pg {

	class Animation	{

	public:
		Animation(
			sf::Shape *shape, 
			sf::Texture *texture, 
			std::vector<sf::IntRect> &frames, 
			std::vector<int> &durations
		);

		void update(int renderFrameTime);

		void play();
		void pause();
		void reset();
		
		~Animation();

	private:
		bool m_playing = false;

		int m_currentFrame = -1;
		int m_timeToFrameChange = 0;

		sf::Shape *m_shape;
		sf::Texture *m_texture;
		std::vector<sf::IntRect> m_frames;
		std::vector<int> m_durations;
	};

}

