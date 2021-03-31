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
            currentBrick = new Brick(widthBrick, heightbrick, 1, "brique_texture.jpg", "brique_texture2.jpg");

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

std::list<Brick*> SpawnerBricks::SpawningCustomBircks(std::vector<std::vector<char>> arrayOfChara, int nbBricksLigne, int nbLigne, int espacement)
{
    std::list<Brick*> listBricks;

    float largeurBrick = (ScreenWidth-(espacement* nbBricksLigne) - (espacement)) / nbBricksLigne;
    float hauteurBrick = ((ScreenHeight/2) - (espacement * nbLigne) - (espacement * 2)) / nbLigne;
    float posSpawnX = espacement;
    float posSpawnY = espacement;

    for (int i = 0; i < arrayOfChara.size(); i++)
    {
        for (int y = 0; y < arrayOfChara[i].size(); y++)
        {
            if (arrayOfChara[i][y] == 'X') 
            {
                //instancier une brique + lajouter a la liste de brique

                Brick* currentBrick;
                currentBrick = new Brick(largeurBrick, hauteurBrick, 2, "brique_texture.jpg", "brique_texture2.jpg");

                //Set le point de pivot et la position
                //Utils::SetOrigin(0.5, 0.5, currentBrick->GetShape());
                currentBrick->GetShape()->setPosition(sf::Vector2f(posSpawnX, posSpawnY));

                //Ajoute la brique a la liste
                listBricks.push_back(currentBrick);
            }
            else
            {
                //rien faire 
            }
            posSpawnX += espacement + largeurBrick;
        }
        posSpawnY += espacement + hauteurBrick;
        posSpawnX = espacement;
    }
    posSpawnY = espacement;

    return listBricks;
}
