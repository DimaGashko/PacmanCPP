#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "GObject.hpp"

namespace pg {

	class Camera {
	public:
		Camera(sf::RenderWindow *window);

		void update();
		void use();
		void init();
		void updateSize();

		void setTarget(GObject *target);
		
		GObject* getTarget();
		sf::Vector2f getCenter();
		sf::View getView();

		~Camera();

	private:
		sf::RenderWindow *m_window;
		sf::View m_view;

		GObject *m_target;
	};

}