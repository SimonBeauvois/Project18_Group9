#define _USE_MATH_DEFINES
#include "Canon.h"
#include "Utils.h"
#include "math.h"
#include <math.h>
#include <iostream>

Canon::Canon(std::string lienFichier)
{
	
	sf::Texture texture;

	if (_texture.loadFromFile(lienFichier)) //If the link is working
	{
		_texture.setSmooth(true);
		_sprite = new sf::Sprite(_texture);
	}
	float width = _sprite->getLocalBounds().width;
	float height = _sprite->getLocalBounds().height;

	_sprite->setScale(sf::Vector2f(0.5, 0.5));
	_sprite->setOrigin(sf::Vector2f(width / 2, height / 2));
	_sprite->setPosition(sf::Vector2f(Utils::ScreenWidth()/2, Utils::ScreenHeight() - 40));
}

void Canon::DrawCanon(sf::RenderWindow& window)
{

	sf::Vector2f screenBottom = sf::Vector2f(Utils::ScreenWidth()/2, Utils::ScreenHeight());
	sf::Vector2f screenTop = sf::Vector2f(Utils::ScreenWidth() / 2, 0);

	sf::Transform transform;

	// Normalized up vector
	sf::Vector2f vectorUp = screenTop - screenBottom;
	math::Normalize(vectorUp);

	// Normalized mouse vector
	sf::Vector2f mouseVector = (sf::Vector2f)sf::Mouse::getPosition(window) - screenBottom;
	math::Normalize(mouseVector);

	float rotateAngle = acosf(math::DotProduct(vectorUp, mouseVector)) * 180/ M_PI;

	if (mouseVector.x < 0) transform.rotate(-rotateAngle, screenBottom);

	else transform.rotate(rotateAngle, screenBottom);
	 
	window.draw(*_sprite, transform);
}



