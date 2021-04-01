
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "Ball.h"
#include "math.h"
#include "Brick.h"
#include "Canon.h"
#include "SpawnerBricks.h"
#include "TextureManager.h"
#include "UIManager.h"
#include <list>
using namespace std;


void main() {

	int numberOfBalls = 5;
	float ballSpawningRate = 50;

	sf::RenderWindow window(sf::VideoMode(Utils::ScreenWidth(), Utils::ScreenHeight()), "MyWindow");

	bool hasCollided = false;

	sf::Clock clock;
	sf::Clock ballClock;
	
	float ballTimer = ballClock.restart().asMilliseconds();

	bool mouseIsClicked = false;
	bool canEnter = false;
	
	TextureManager::loadTexture();

	UIManager* UiManager = new UIManager();
	
	sf::Vector2i mousePos;
	sf::Vector2f direction;

	Canon* canon = new Canon("canon.png");

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

	std::list<Ball*> listOfBalls;
	int currentBallIndex = 0;

	while (window.isOpen()) {
		
		float deltaTime = clock.restart().asSeconds();
		
		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {

				window.close();

			}

			if (event.type == sf::Event::MouseButtonPressed && !mouseIsClicked) {

				UiManager->increaseCompteurTir(1);
				mousePos = sf::Mouse::getPosition(window);

				direction = (sf::Vector2f)mousePos - sf::Vector2f(Utils::ScreenWidth() / 2, Utils::ScreenHeight());
				math::Normalize(direction);

				mouseIsClicked = true;
				canEnter = true;
			}
		}

		// Initializes a burst of balls
		if (mouseIsClicked && canEnter && ballClock.getElapsedTime().asMilliseconds() > ballSpawningRate)
		{
			if (listOfBalls.size() < numberOfBalls) {

				Ball* ball = new Ball(12);
				listOfBalls.push_back(ball);
				ball->SetBall(sf::Vector2f(Utils::ScreenWidth() / 2, Utils::ScreenHeight()));
				ball->Launch(direction);

				ballTimer = ballClock.restart().asMilliseconds();

				if (listOfBalls.size() == numberOfBalls) {
					canEnter = false;
				}
			}

			else if (listOfBalls.size() == numberOfBalls) {

				std::list<Ball*>::iterator currentBall = listOfBalls.begin();

				advance(currentBall, currentBallIndex);
				(*currentBall)->Launch(direction);

				ballTimer = ballClock.restart().asMilliseconds();

				if (currentBallIndex == listOfBalls.size() - 1) {
					currentBallIndex = 0;
					canEnter = false;
				}
				else currentBallIndex++;
			}

		}
		
		// Checks the collision from every balls
		for (std::list<Ball*>::iterator ballIt = listOfBalls.begin(); ballIt != listOfBalls.end(); ballIt++)
		{
			for (std::list<Brick*>::iterator it = listOfBricks.begin(); it != listOfBricks.end(); it++)
			{
				if ((*ballIt)->CheckCollisionWithEntity(*it) && (*it)->GetLife() > 0) {

					if ((*it)->TakeDamage() < 1) {

						// Destroy the brick
						listOfBricks.erase(it);

					}
					break;
				}
			}
		}

		
		if (hasCollided) {
			hasCollided = false;
		}


		int i = 0;
		bool allBallsOutOfScreen = false;
		// Computes the movement of the balls and the collisions with the screen
		for (std::list<Ball*>::iterator ballIt = listOfBalls.begin(); ballIt != listOfBalls.end(); ballIt++)
		{
			(*ballIt)->Move(deltaTime);
			allBallsOutOfScreen = (*ballIt)->CheckCollisionWithScreen();

			if ((*ballIt)->CheckCollisionWithScreen()) {

				(*ballIt)->SetBall(sf::Vector2f(Utils::ScreenWidth() / 2, Utils::ScreenHeight()));

			}
			++i;
		}

		if (allBallsOutOfScreen) {
			mouseIsClicked = false;
		}

		window.clear();
		window.draw(spriteFond);
		

		for (std::list<Ball*>::iterator ballIt = listOfBalls.begin(); ballIt != listOfBalls.end(); ballIt++)
		{
			(*ballIt)->Draw(window);
		}

		for (std::list<Brick*>::iterator it = listOfBricks.begin(); it != listOfBricks.end(); ++it)
		{

			if ((*it)->GetLife() > 0) {

				(*it)->Draw(window);
			}
		}

		canon->DrawCanon(window);
		window.draw(UiManager->getTextScore());

		window.display();
		
	
	}



}

