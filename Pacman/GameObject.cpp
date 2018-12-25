#include "GameObject.hpp"
 
namespace pg {

	GameObject::GameObject() :
		m_isMovable(false),
		m_isObstacle(false)
	{
		
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

	void GameObject::setTexture(sf::Texture *texture) {
		m_rect.setTexture(texture);
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

		return sf::FloatRect(pos.x+1, pos.y+1, size.x-2, size.y-2);
	}

	sf::Vector2f GameObject::getPosition() {
		return m_rect.getPosition();
	}

	void GameObject::setPosition(sf::Vector2f coords) {
		m_rect.setPosition(coords); 
	}

	void GameObject::setEndPos(sf::Vector2f coords) {
		m_rect.setPosition(coords - getSize());
	}

	sf::Vector2f GameObject::getEndPos() {
		return getPosition() + getSize();
	}

	sf::Vector2f GameObject::getTopRight() {
		auto pos = getPosition();
		auto size = getSize();

		return sf::Vector2f(pos.x + size.x, pos.y);
	}

	void GameObject::setTopRight(sf::Vector2f coords) {
		auto size = getSize();
		setPosition(sf::Vector2f(coords.x - size.x, coords.y));
	}

	sf::Vector2f GameObject::getBottomLeft() {
		auto pos = getPosition();
		auto size = getSize();

		return sf::Vector2f(pos.x, pos.y + size.y);
	}

	void GameObject::setBottomLeft(sf::Vector2f coords) {
		auto size = getSize();
		setPosition(sf::Vector2f(coords.x, coords.y - size.y));
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

	void GameObject::setPosInGrid(sf::Vector2i *coords) {
		m_posInGrid = coords;
	}

	sf::Vector2i* GameObject::getPosInGrid() {
		return m_posInGrid;
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

	bool GameObject::isObstacle() {
		return m_isObstacle;
	}

	bool GameObject::isDead() {
		return m_isDead;
	}

	bool GameObject::isMovable() {
		return m_isMovable;
	}

	GameObject::~GameObject() {
		delete m_posInGrid;
	}

} //namespace pg