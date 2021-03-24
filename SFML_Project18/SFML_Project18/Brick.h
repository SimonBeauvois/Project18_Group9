#pragma once
#include "Entity.h"

class Brick : public Entity
{
public:
	Brick(float width, float height);

private:

	float _width;
	float _height;
};

