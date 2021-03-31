#pragma once
#include "Entity.h"

class Brick : public Entity
{
public:
	Brick(float width, float height, int life, std::string lienTexture, std::string lienTexture2);

	~Brick();

	int TakeDamage();

	int GetLife() { return _life; }

	void updateTexture();

private:

	float _width;
	float _height;

	sf::Texture _texture;
	sf::Texture _texture2;

	int _life = 2;
};

