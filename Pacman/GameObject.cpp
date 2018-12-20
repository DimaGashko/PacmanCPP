#include "GameObject.hpp"
 
namespace pg {

	GameObject::GameObject() {
		m_rect.setSize(sf::Vector2f(16, 16));
		m_rect.setPosition(sf::Vector2f(16, 16));
		m_rect.setFillColor(sf::Color::Green);
	}

	void GameObject::draw(sf::RenderTarget &window) {
		window.draw(m_rect);
	}

	GameObject::~GameObject() {

	}

} //namespace pg