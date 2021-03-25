#pragma once
#include "Entity.h"

class Brick : public Entity
{
public:
	Brick(float width, float height, int life);

	~Brick();

	int TakeDamage();

	int GetLife() { return _life; }

private:

	float _width;
	float _height;

	int _life = 1;
};

