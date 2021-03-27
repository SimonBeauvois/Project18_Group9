using namespace std;
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "Ball.h"
#include "math.h"
#include "Brick.h"
#include "Canon.h"
#include <list>


void main() {

	sf::RenderWindow window(sf::VideoMode(Utils::ScreenWidth(), Utils::ScreenHeight()), "MyWindow");

	bool hasCollided = false;

	sf::Clock clock;
	
	bool mouseIsClicked = false;
	
	Canon* canon = new Canon(10, 100);
	canon->SetPosition(sf::Vector2f(0.5, 0.95));

	Ball* ball = new Ball(12);

	ball->SetPosition(sf::Vector2f(0.5, 0.8));

	Brick* brick = new Brick(120, 70,1);

	brick->SetPosition(sf::Vector2f(0.5, 0.1));

	Brick* brick2 = new Brick(120, 70,1);

	brick2->SetPosition(sf::Vector2f(0.2, 0.25));

	sf::Vector2i mousePos;
	sf::Vector2f direction;


	std::list<Brick*> listOfBricks;
	listOfBricks.push_back(brick);
	listOfBricks.push_back(brick2);

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

		for (std::list<Brick*>::iterator it = listOfBricks.begin(); it != listOfBricks.end(); ++it)
		{
			// Collide only if the ball has not collided with something yet
			
			if (!hasCollided && (*it)->GetLife() > 0) {

				hasCollided = ball->CheckCollisionWithEntity(*it);

				if (hasCollided) {

					(*it)->TakeDamage();

				}
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
			// Collide only if the ball has not collided with something yet

			if ((*it)->GetLife() > 0) {

				(*it)->Draw(window);
			}
		}

		window.display();
		
	
	}



}

