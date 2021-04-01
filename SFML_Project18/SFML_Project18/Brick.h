#pragma once
#include "Entity.h"

class Brick : public Entity
{
public:
	Brick(float width, float height, int life);

	~Brick();

	int TakeDamage();

	int GetLife() { return _life; }

	void updateTexture();

private:
	float _width;
	float _height;

	sf::Texture _texture;
	sf::Texture _texture2;
	sf::Texture _texture3;

	std::string lienTexture = "brique_texture_alien.jpg";
	std::string lienTexture2 = "brique_texture_alien2.jpg";
	std::string lienTexture3 = "brique_texture_alien3.jpg";

	int _life;
};

