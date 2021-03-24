#include "Entity.h"
#include "Utils.h"

Entity::Entity()
{
}

void Entity::SetPosition(sf::Vector2f coeffs)
{
	_shape->setPosition(coeffs.x * Utils::ScreenWidth(), coeffs.y * Utils::ScreenHeight());
}



void Entity::Launch(sf::Vector2f vect)
{
	_vX = vect.x;
	_vY = vect.y;
}

void Entity::Draw(sf::RenderWindow& window)
{
	window.draw(*_shape);
}

void Entity::SetAnchors(float xAnch, float yAnch)
{
	Utils::SetOrigin(xAnch, yAnch, _shape);
}

void Entity::ChangeColor()
{
	_shape->setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
}



