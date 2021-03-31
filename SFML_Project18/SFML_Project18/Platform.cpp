#include "Platform.h"
#include "Entity.h"
#include <math.h>
#include "Utils.h"


Platform::Platform(float largeur, float longueur, float speedP)
{
    _shape = new sf::RectangleShape(sf::Vector2f(largeur, longueur));
    speed = speedP;
    //mettre la platforme en bas de l'ecran
    Entity::SetAnchors(0.5, 0.5);
    _shape->setPosition(Utils::ScreenWidth() / 2, Utils::ScreenHeight() - (longueur / 2));
}

//void Platform::move(float deltaTime)
//{
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
//    {
//        _vX = -1;
//    }
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//    {
//        _vX = 1;
//    }
//
//    _shape->move(sf::Vector2f(_vX, 0) * speed * deltaTime);
//}
//
//void Platform::checkCollisionScreen()
//{
//}