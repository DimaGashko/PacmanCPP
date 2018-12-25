#pragma once

#include <SFML/Graphics.hpp>

namespace pg {

	class Animation	{

	public:
		Animation(
			sf::Shape *shape, 
			sf::Texture &texture, 
			std::vector<sf::IntRect> &frames, 
			std::vector<int> &durations
		);

		void update(int renderFrameTime);

		void play();
		void pause();
		
		~Animation();

	private:
		int m_currentFrame = -1;
		bool m_playing = false;

		int m_timeToFrameChange;

		sf::Shape *m_shape;
		sf::Texture m_texture;
		std::vector<sf::IntRect> m_frames;
		std::vector<int> m_durations;
	};

}

