#include "GameObject.hpp"
 
namespace pg {

	GameObject::GameObject() {
		init();
	}

	GameObject::GameObject(sf::Texture *texture) {
		init();
		m_rect.setTexture(texture);
	}

	void GameObject::init() {
		
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

	void GameObject::move(sf::Vector2f offset) {
		m_rect.move(offset);
	}

	void GameObject::setSize(sf::Vector2f size) {
		m_rect.setSize(size);
	}

	GameObject::~GameObject() {
		delete m_rect.getTexture();
	}

} //namespace pg