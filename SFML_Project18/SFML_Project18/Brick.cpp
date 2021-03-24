#include "Brick.h"

Brick::Brick(float width, float height) {
	_width = width;
	_height = height;

	_shape = new sf::RectangleShape(sf::Vector2f(_width, _height));
}