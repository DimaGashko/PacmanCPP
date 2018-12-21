#include "GameObject.hpp"
 
namespace pg {

	GameObject::GameObject() :
		m_real(false)
	{
		m_rect.setSize(sf::Vector2f(16, 16));
		m_rect.setFillColor(sf::Color::Green);
	}

	GameObject::GameObject(sf::Vector2f coords) :
		GameObject()
	{
		m_rect.setPosition(coords);
	}

	void GameObject::draw(sf::RenderTarget &window) {
		window.draw(m_rect);
	}

	sf::Vector2f GameObject::getPosition() {
		return m_rect.getPosition();
	}

	void GameObject::setPosition(sf::Vector2f coords) {
		m_rect.setPosition(coords);
	}

	GameObject::~GameObject() {

	}

} //namespace pg