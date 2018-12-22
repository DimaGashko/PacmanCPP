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

		auto cameraSize = sf::Vector2f(100, 100);
		auto targCenter = m_target->getCenter();
		auto cameraCenter = m_view.getCenter();

		if (targCenter.x > cameraCenter.x + cameraSize.x) {
			cameraCenter.x = targCenter.x - cameraSize.x;
		}
		else if (cameraCenter.x > targCenter.x + cameraSize.x) {
			cameraCenter.x = targCenter.x + cameraSize.x;
		}

		if (targCenter.y > cameraCenter.y + cameraSize.y) {
			cameraCenter.y = targCenter.y - cameraSize.y;
		}
		else if (cameraCenter.y > targCenter.y + cameraSize.y) {
			cameraCenter.y = targCenter.y + cameraSize.y;
		}

		m_view.setCenter(cameraCenter);

		use();
	}

	void Camera::updateSize() {
		auto size = m_window->getSize();
		m_view.setSize(sf::Vector2f(size.x / 2.f, size.y / 2.f));
	}

	void Camera::setTarget(GameObject * target) {
		m_target = target;

		if (!m_target) return;

		m_view.setCenter(m_target->getPosition());
	}

	GameObject* Camera::getTarget() {
		return m_target;
	}

	Camera::~Camera() {

	}

}; // namespace pg