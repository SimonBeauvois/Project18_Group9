#define _USE_MATH_DEFINES
#include "Canon.h"
#include "Utils.h"
#include "math.h"
#include <math.h>
#include <iostream>

Canon::Canon(float width, float height)
{
	_width = width;
	_height = height;

	_shape = new sf::RectangleShape(sf::Vector2f(_width, _height));
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
	 

	window.draw(*_shape, transform);

}
