#include "GObject.hpp"
 
namespace pg {

	GObject::GObject() :
		m_isMovable(false),
		m_isObstacle(false)
	{
		
	}

	void GObject::update(int frameTime) {
		updateSpeed(frameTime);
		updateAnimation(frameTime);
		_useAnimation(frameTime);
	}

	void GObject::updatePos() {
		move(m_speed);

		m_speed.x = 0;
		m_speed.y = 0;
	}

	inline void GObject::_useAnimation(int frameTime) {
		if (m_animationManager == NULL) return;
		m_animationManager->update(frameTime);
	}

	void GObject::draw(sf::RenderTarget &window) {
		window.draw(m_rect);
	}

	void GObject::setAnimations(
		sf::Texture *texture, 
		std::vector<std::string> &names, 
		std::vector<std::vector<sf::IntRect>> &frames, 
		std::vector<std::vector<int>> &durations
	) { 
		
		m_animationManager = new AnimationManager(&m_rect, texture, names, frames, durations);
		setStartAnim();
	}

	void GObject::setTexture(sf::Texture *texture, sf::IntRect textureRect) {
		m_rect.setTexture(texture);
		m_rect.setTextureRect(textureRect);
	}

	bool GObject::intersects(GObject *obj) {
		if (obj == this) return false;

		auto a = getBounds();
		auto b = obj->getBounds();

		return Math::intersectsNormalRect(
			a.left, a.top, a.left + a.width, a.top + a.height,
			b.left, b.top, b.left + b.width, b.top + b.height
		);
	}

	sf::FloatRect GObject::getBounds() {
		auto pos = getPosition();
		auto size = getSize();

		return sf::FloatRect(pos.x+1, pos.y+1, size.x-2, size.y-2);
	}

	void GObject::move(sf::Vector2f offset) {
		m_rect.move(offset);
	}

	void GObject::setPosInGrid(sf::Vector2i *coords) {
		m_posInGrid = coords;
	}

	sf::Vector2i* GObject::getPosInGrid() {
		return m_posInGrid;
	}

	bool GObject::die() {
		m_isDead = true;

		//if (m_onDead == NULL) {
			m_onDead();
		//}
		
		return true;
	}

	void GObject::setOnDead(std::function<void()> onDead) {
		m_onDead = onDead;
	}

	void GObject::addToSpeed(sf::Vector2f dSpeed) {
		m_speed += dSpeed;
	}

	void GObject::setPosition(sf::Vector2f coords) {
		m_rect.setPosition(coords);
	}

	void GObject::setCenter(sf::Vector2f center) {
		setPosition(center - getSize() / 2.f);
	}

	void GObject::setSpeed(sf::Vector2f speed) {
		m_speed = speed;
	}

	void GObject::setSize(sf::Vector2f size) {
		m_rect.setSize(size);
	}

	sf::Vector2f GObject::getPosition() {
		return m_rect.getPosition();
	}

	sf::Vector2f GObject::getCenter() {
		return getPosition() + getSize() / 2.f;
	}

	sf::Vector2f GObject::getSpeed() {
		return m_speed;
	}

	sf::Vector2f GObject::getSize() {
		return m_rect.getSize();
	}

	void GObject::setLeft(float val) {
		setPosition(sf::Vector2f(val, getPosition().y));
	}

	void GObject::setTop(float val) {
		setPosition(sf::Vector2f(getPosition().x, val));
	}

	void GObject::setRight(float val) {
		setPosition(sf::Vector2f(val - getSize().x, getPosition().y));
	}

	void GObject::setBottom(float val) {
		setPosition(sf::Vector2f(getPosition().x, val - getSize().y));
	}

	float GObject::getLeft() {
		return getPosition().x;
	}

	float GObject::getTop() {
		return getPosition().y;
	}

	float GObject::getRight() {
		return getPosition().x + getSize().x;
	}

	float GObject::getBottom() {
		return getPosition().y + getSize().y;
	}

	bool GObject::isObstacle() {
		return m_isObstacle;
	}

	bool GObject::isDead() {
		return m_isDead;
	}

	bool GObject::isMovable() {
		return m_isMovable;
	}

	GObject::~GObject() {
		delete m_posInGrid;
	}

} //namespace pg