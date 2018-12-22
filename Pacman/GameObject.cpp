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
		auto a = m_rect.getLocalBounds();
	}

	void GameObject::draw(sf::RenderTarget &window) {
		window.draw(m_rect);
	}

	bool GameObject::intersects(GameObject *obj) {
		if (obj == this) return false;

		return getBounds().intersects(obj->getBounds());
	}

	sf::FloatRect GameObject::getBounds() {
		auto bounds = m_rect.getGlobalBounds();

		bounds.left += 1;
		bounds.top += 1;
		bounds.width -= 1;
		bounds.height -= 1;

		return bounds;
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
		return getPosition() + getSize() / 2.f;
	}

	void GameObject::setCenter(sf::Vector2f center) {
		setPosition(center - getSize() / 2.f);
	}

	void GameObject::update() {
		
	}

	GameObject::~GameObject() {
		delete m_rect.getTexture();
	}

} //namespace pg