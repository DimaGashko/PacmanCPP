#include "Camera.hpp"

namespace pg {

	Camera::Camera(sf::RenderWindow *window) :
		m_window(window)
	{

	}

	void Camera::use() {
		m_window->setView(m_view);
	}

	void Camera::init() {
		updateSize();
		use();
	}

	void Camera::update() {
		if (!m_target) return;

		m_view.setCenter(m_target->getPosition());

		use();
	}

	void Camera::updateSize() {
		auto size = m_window->getSize();
		m_view.setSize(sf::Vector2f(size.x / 2.f, size.y / 2.f));
	}

	void Camera::setTarget(GameObject * target) {
		m_target = target;
	}

	GameObject* Camera::getTarget() {
		return m_target;
	}

	Camera::~Camera() {

	}

}; // namespace pg