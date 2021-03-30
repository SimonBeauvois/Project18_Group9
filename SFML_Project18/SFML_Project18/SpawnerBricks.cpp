#include "SpawnerBricks.h"
#include "Utils.h"
#include "Brick.h"
#include <list>

int ScreenWidth = Utils::ScreenWidth();
int ScreenHeight = Utils::ScreenHeight();

std::list<Brick*> SpawnerBricks::SpawningBricks(float nbLigne, float widthBrick, float heightbrick, float espacement)
{
    std::list<Brick*> listBricks;

    int nbBrickLigne = (ScreenWidth - espacement)/ widthBrick;
    float ecartVideTotal = ScreenWidth - (nbBrickLigne * widthBrick);
    float ecartBetweenBricks = ecartVideTotal / (nbBrickLigne + 1);

    float distanceX = ecartBetweenBricks + (widthBrick / 2);

    float paddingY = 20;
    float margeTop = (heightbrick / 2) + paddingY;


    for (size_t y = 0; y < nbLigne; y++)
    {
        for (size_t i = 0; i < nbBrickLigne; i++)
        {
            Brick* currentBrick;
            currentBrick = new Brick(widthBrick, heightbrick, 1);

            //Set le point de pivot et la position
            Utils::SetOrigin(0.5, 0.5, currentBrick->GetShape());
            currentBrick->GetShape()->setPosition(sf::Vector2f(distanceX, margeTop));

            //Ajoute la brique a la liste
            listBricks.push_back(currentBrick);

            distanceX += (ecartBetweenBricks + widthBrick);
        }
        distanceX = ecartBetweenBricks + (widthBrick / 2);
        margeTop += (paddingY + heightbrick);
    }

    return listBricks;
}