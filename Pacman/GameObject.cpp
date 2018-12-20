#include "GameObject.hpp"
 
namespace pg {

	GameObject::GameObject() :
		m_sprite(sf::Sprite())
	{
		
	}
	
	GameObject::GameObject(sf::Vector2f position) :
		GameObject()
	{
		m_sprite.setPosition(position);
	}


	GameObject::~GameObject() {

	}

} //namespace pg