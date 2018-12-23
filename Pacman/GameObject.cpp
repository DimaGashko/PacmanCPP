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

	void GameObject::update() {
		updatePos();
	}

	void GameObject::updatePos() {
		move(m_speed);

		m_speed.x = 0;
		m_speed.y = 0;
	}

	void GameObject::draw(sf::RenderTarget &window) {
		window.draw(m_rect);
	}

	bool GameObject::intersects(GameObject *obj) {
		if (obj == this) return false;

		auto a = getBounds();
		auto b = obj->getBounds();

		return Math::intersectsNormalRect(
			a.left, a.top, a.left + a.width, a.top + a.height,
			b.left, b.top, b.left + b.width, b.top + b.height
		);
	}

	sf::FloatRect GameObject::getBounds() {
		auto pos = getPosition();
		auto size = getSize();

		return sf::FloatRect(pos.x, pos.y, size.x, size.y);
	}

	sf::Vector2f GameObject::getPosition() {
		return m_rect.getPosition();
	}

	sf::Vector2f GameObject::getEndPos() {
		return getPosition() + getSize();
	}

	void GameObject::setPosition(sf::Vector2f coords) {
		m_rect.setPosition(coords);
	}

	void GameObject::setEndPos(sf::Vector2f coords) {
		m_rect.setPosition(coords - getSize());
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

	void GameObject::addToSpeed(sf::Vector2f dSpeed) {
		m_speed += dSpeed;
	}

	void GameObject::setSpeed(sf::Vector2f speed) {
		m_speed = speed;
	}

	sf::Vector2f GameObject::getSpeed() {
		return m_speed;
	}

	void GameObject::setCenter(sf::Vector2f center) {
		setPosition(center - getSize() / 2.f);
	}

	GameObject::~GameObject() {
		delete m_rect.getTexture();
	}

} //namespace pg