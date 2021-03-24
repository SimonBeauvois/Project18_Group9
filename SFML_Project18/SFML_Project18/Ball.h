#pragma once
#include "Entity.h"


class Ball : public Entity
{
public:
	Ball(float radius);

	void Move(float);

	void CheckCollisionWithScreen();

	void CheckCollisionWithEntity(Entity* entity);

private:
	float _radius;
};

