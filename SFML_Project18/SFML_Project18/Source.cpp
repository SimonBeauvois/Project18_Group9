
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "Ball.h"
#include "math.h"
#include "Brick.h"
#include "Canon.h"
#include "SpawnerBricks.h"
#include "TextureManager.h"
#include <list>
using namespace std;


void main() {

	sf::RenderWindow window(sf::VideoMode(Utils::ScreenWidth(), Utils::ScreenHeight()), "MyWindow");

	bool hasCollided = false;

	sf::Clock clock;
	
	bool mouseIsClicked = false;
	
	TextureManager::loadTexture();
	
	Ball* ball = new Ball(12);
	ball->SetBall(sf::Vector2f(Utils::ScreenWidth() / 2, Utils::ScreenHeight()));
	sf::Vector2i mousePos;
	sf::Vector2f direction;

	Canon* canon = new Canon("canon.png");

	//std::list<Brick*> listOfBricks = SpawnerBricks::SpawningBricks(3, 50, 40, 100);
	std::vector<std::vector<int>> arrayOfChara = 
	{ 
		{1,1,1,1,1,1} , 
		{1,2,2,2,2,1} , 
		{1,2,3,3,2,1} , 
		{1,2,3,3,2,1}, 
		{1,2,2,2,2,1}, 
		{1,1,1,1,1,1} 
	};
	std::list<Brick*> listOfBricks = SpawnerBricks::SpawningCustomBircks(arrayOfChara, 6, 6, 10);

	sf::Sprite spriteFond;
	spriteFond.setOrigin(sf::Vector2f(.5f * spriteFond.getGlobalBounds().width, .5f * spriteFond.getGlobalBounds().height));
	spriteFond.setPosition(0, 0);
	spriteFond.setScale(1.2, 1.2);
	spriteFond.setTexture(TextureManager::_textureFond);

	while (window.isOpen()) {
		
		float deltaTime = clock.restart().asSeconds();
		
		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::MouseButtonPressed && !mouseIsClicked) {

				mousePos = sf::Mouse::getPosition(window);

				direction = (sf::Vector2f)mousePos - ball->GetShape()->getPosition();
				math::Normalize(direction);

				mouseIsClicked = true;
				ball->Launch(direction);
			}
		}


		
		for (std::list<Brick*>::iterator it = listOfBricks.begin(); it != listOfBricks.end(); it++)
		{
			if (ball->CheckCollisionWithEntity(*it) && (*it)->GetLife() > 0) {

				if ((*it)->TakeDamage() < 1) {

					// Destroy the brick
					listOfBricks.erase(it);
				}
				break;
			}
		}

		
		if (hasCollided) {
			hasCollided = false;
		}


		ball->Move(deltaTime);

		if (ball->CheckCollisionWithScreen()) {

			ball->SetBall(sf::Vector2f(Utils::ScreenWidth()/2, Utils::ScreenHeight()));
			mouseIsClicked = false;
		}

		window.clear();

		window.draw(spriteFond);
		ball->Draw(window);
		canon->DrawCanon(window);

		for (std::list<Brick*>::iterator it = listOfBricks.begin(); it != listOfBricks.end(); ++it)
		{
			

			if ((*it)->GetLife() > 0) {

				(*it)->Draw(window);
			}
		}

		window.display();
		
	
	}



}

