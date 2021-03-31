#include "Brick.h"

Brick::Brick(float width, float height, int life, std::string lienTexture, std::string lienTexture2) {
	_width = width;
	_height = height;

	_shape = new sf::RectangleShape(sf::Vector2f(_width, _height));

	if (_texture.loadFromFile(lienTexture)) //si le lien est fonctionnel
	{
		_texture.setSmooth(true);
		_texture.setRepeated(true);
		_shape->setTexture(&_texture);
	}
	if (_texture2.loadFromFile(lienTexture2)) //si le lien est fonctionnel
	{
		_texture2.setSmooth(true);
	}
}

Brick::~Brick()
{
	delete(_shape);
}

int Brick::TakeDamage()
{
	--_life;

	if(_life == 1){ _shape->setTexture(&_texture2); }

	return _life;
}

void Brick::updateTexture()
{
}
