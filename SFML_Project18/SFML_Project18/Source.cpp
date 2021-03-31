
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "Ball.h"
#include "math.h"
#include "Brick.h"
#include "Canon.h"
#include "SpawnerBricks.h"
#include <list>
using namespace std;


void main() {

	sf::RenderWindow window(sf::VideoMode(Utils::ScreenWidth(), Utils::ScreenHeight()), "MyWindow");

	bool hasCollided = false;

	sf::Clock clock;
	
	bool mouseIsClicked = false;
	
	

	Ball* ball = new Ball(12);

	ball->SetPosition(sf::Vector2f(0.5, 0.8));

	sf::Vector2i mousePos;
	sf::Vector2f direction;

	Canon* canon = new Canon("canon.png");
	//canon->setPosition(sf::Vector2f(0.5, 0.95));

	//std::list<Brick*> listOfBricks = SpawnerBricks::SpawningBricks(3, 50, 40, 100);
	std::vector<std::vector<char>> arrayOfChara = { {'X','X','X'} , {'X','X','X'} , {'X','X','X'} };
	std::list<Brick*> listOfBricks = SpawnerBricks::SpawningCustomBircks(arrayOfChara, 3, 3, 40);
	
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

		window.clear();

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

