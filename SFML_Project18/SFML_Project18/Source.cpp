#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "Ball.h"
#include "math.h"
#include "Brick.h"


void main() {

	sf::RenderWindow window(sf::VideoMode(Utils::ScreenWidth(), Utils::ScreenHeight()), "MyWindow");


	sf::Clock clock;
	
	bool mouseIsClicked = false;
	

	Ball* ball = new Ball(12);

	ball->SetPosition(sf::Vector2f(0.5, 0.8));

	Brick* brick = new Brick(120, 70);

	brick->SetPosition(sf::Vector2f(0.5, 0.1));

	Brick* brick2 = new Brick(120, 70);

	brick2->SetPosition(sf::Vector2f(0.2, 0.25));

	sf::Vector2i mousePos;
	sf::Vector2f direction;

	while (window.isOpen()) {
		
		float deltaTime = clock.restart().asSeconds();
		
		ball->Draw(window);
		brick->Draw(window);
		brick2->Draw(window);

		window.display();
		
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

		ball->CheckCollisionWithEntity(brick);
		ball->CheckCollisionWithEntity(brick2);
		ball->Move(deltaTime);

		window.clear();
	
	}



}

