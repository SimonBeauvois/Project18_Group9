#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Brick.h"

class SpawnerBricks
{
public:
    static std::list<Brick*> SpawningBricks(float nbLigne, float widthBrick, float heightbrick, float espacement);

    // static permet de ne pas instancier un classe pour utiliser ses fonctions.
};
