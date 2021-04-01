#include "Brick.h"
#include "TextureManager.h"

Brick::Brick(float width, float height, int life, bool bonusBrick) {
    _width = width;
    _height = height;
    _life = life;
    _shape = new sf::RectangleShape(sf::Vector2f(_width, _height));
    _bonusBrick = bonusBrick;

	updateTexture();
}

Brick::~Brick()
{
	delete(_shape);
}

int Brick::TakeDamage()
{
	--_life;

	updateTexture();

	return _life;
}

void Brick::updateTexture()
{
	if (_life > 2) { _shape->setTexture(TextureManager::_texture); }
	if (_life == 2) { _shape->setTexture(TextureManager::_texture2); }
	if (_life == 1) { _shape->setTexture(TextureManager::_texture3); }
    if (_bonusBrick) { _shape->setTexture(TextureManager::_textureBonus); }
}
