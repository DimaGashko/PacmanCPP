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

	sf::Vector2f GameObject::getSize() {
		return m_rect.getSize();
	}

	sf::Vector2f GameObject::getCenter() {
		auto coords = getPosition();
		auto size = getSize();

		return sf::Vector2f(
			coords.x + size.x / 2,
			coords.y + size.y / 2
		);
	}

	void GameObject::setCenter(sf::Vector2f) {

	}

	GameObject::~GameObject() {
		delete m_rect.getTexture();
	}

} //namespace pg