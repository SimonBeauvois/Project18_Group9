#include "Brick.h"
#include "TextureManager.h"

Brick::Brick(float width, float height, int life) {
	_width = width;
	_height = height;
	_life = life;
	_shape = new sf::RectangleShape(sf::Vector2f(_width, _height));

	//if (_texture.loadFromFile(lienTexture)&& _texture2.loadFromFile(lienTexture2)&& _texture3.loadFromFile(lienTexture3)) //si le lien est fonctionnel
	//{
	//	_texture.setSmooth(true);
	//	_texture.setRepeated(true);
	//	updateTexture();
	//}
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
}
