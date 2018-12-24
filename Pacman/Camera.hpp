#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "GameObject.hpp"

namespace pg {

	class Camera {
	public:
		Camera(sf::RenderWindow *window);

		void update();
		void use();
		void init();
		void updateSize();

		void setTarget(GameObject *target);
		
		GameObject* getTarget();
		sf::Vector2f getCenter();
		sf::View getView();

		~Camera();

	private:
		sf::RenderWindow *m_window;
		sf::View m_view;

		GameObject *m_target;
	};

}