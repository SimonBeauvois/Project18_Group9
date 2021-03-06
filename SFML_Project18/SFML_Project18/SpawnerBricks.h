#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Brick.h"

class SpawnerBricks
{
public:
    static std::list<Brick*> SpawningBricks(float nbLigne, float widthBrick, float heightbrick, float espacement);

    static std::list<Brick*> SpawningCustomBircks(std::vector<std::vector<int>> arrayOfChara, int nbBricksLigne, int nbLigne, int espacement);
};
