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

		auto winSize = m_view.getSize();
		auto cameraSize = sf::Vector2f(winSize.x * 0.25f, winSize.x * 0.25f);
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
		m_view.setSize(sf::Vector2f(size));
		m_view.zoom(0.5);
		use();
	}

	void Camera::setTarget(GameObject * target) {
		m_target = target;

		if (!m_target) return;

		m_view.setCenter(m_target->getPosition());
	}

	GameObject* Camera::getTarget() {
		return m_target;
	}

	sf::Vector2f Camera::getCenter() {
		return m_view.getCenter();
	}

	sf::View Camera::getView() {
		return m_view;
	}

	Camera::~Camera() {

	}

}; // namespace pg