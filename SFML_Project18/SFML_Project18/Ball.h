#pragma once
#include "Entity.h"


class Ball : public Entity
{
public:
    Ball(float radius);

    void Move(float);

    bool CheckCollisionWithScreen();

    bool CheckCollisionWithEntity(Entity* entity);

    void Launch(sf::Vector2f vect);

    void SetBall(sf::Vector2f pos);

private:
    float _radius;
    bool _isOut = true;

    float _vX = 0;
    float _vY = 0;
    float _moveSpeed = 750;
};

