#include "Brick.h"

Brick::Brick(float width, float height, int life) {
	_width = width;
	_height = height;

	_shape = new sf::RectangleShape(sf::Vector2f(_width, _height));
}

Brick::~Brick()
{
	delete(_shape);
}

int Brick::TakeDamage()
{
	--_life;

	return _life;
}
