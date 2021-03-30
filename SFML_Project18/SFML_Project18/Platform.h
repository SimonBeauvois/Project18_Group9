#pragma once
#include "Entity.h"

class Platform : public Entity
{
public:
    Platform(float largeur, float longueur, float speedP);

    float speed;
    float Vx;
    void move(float deltaTime);
    void checkCollisionScreen();
};