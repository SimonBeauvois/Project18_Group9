#pragma once
#include "Entity.h"

class Brick : public Entity
{
public:
	Brick(float width, float height, int life, bool bonusBrick = false);

	~Brick();

	int TakeDamage();

	int GetLife() { return _life; }

	void updateTexture();

	bool IsBonusBrick() { return _bonusBrick; }

private:
	float _width;
	float _height;

	bool _bonusBrick;

	int _life;
};

