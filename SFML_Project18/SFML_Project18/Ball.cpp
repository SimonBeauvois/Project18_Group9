#include "Ball.h"
#include <math.h>
#include "Utils.h"

Ball::Ball(float radius) {

	_radius = radius;
	_shape = new sf::CircleShape(_radius);

	float diameter = _shape->getLocalBounds().width;

	_shape->setOrigin(sf::Vector2f(diameter / 2, 0));

	ChangeColor();
}


void Ball::Launch(sf::Vector2f vect)
{
	_vX = vect.x;
	_vY = vect.y;
}

bool Ball::CheckCollisionWithScreen() {

	sf::FloatRect currentBox = _shape->getGlobalBounds();

	// Left
	if (currentBox.left + _vX < 0) {
		_vX *= -1;
		ChangeColor();
	}

	// Top
	if (currentBox.top + _vY < 0) {
		_vY *= -1;
		ChangeColor();
	}

	// Right
	if (currentBox.left + currentBox.width + _vX > Utils::ScreenWidth()) {
		_vX *= -1;
		ChangeColor();
	}

	// Bottom
	if (currentBox.top + _vY > Utils::ScreenHeight()) {
		return true;
	}

	return false;
}

bool Ball::CheckCollisionWithEntity(Entity* entity)
{
	sf::Shape* otherShape = entity->GetShape();

	sf::FloatRect currentBox = _shape->getGlobalBounds();
	sf::FloatRect otherBox = otherShape->getGlobalBounds();

	float circleXmin = currentBox.left;
	float circleXmax = currentBox.left + currentBox.width;
	float circleYmin = currentBox.top;
	float circleYmax = currentBox.top + currentBox.height;

	float otherXmin = otherBox.left;
	float otherXax = otherBox.left + otherBox.width;
	float otherYmin = otherBox.top;
	float otherYmax = otherBox.top + otherBox.height;

	if (currentBox.intersects(otherBox)) {

		std::string min;


		// Check top
		float distTop = abs(otherBox.top + otherBox.height - currentBox.top);
		float minDist = distTop;
		min = "top";

		// Check bot
		float distBot = abs(currentBox.top + currentBox.height - otherBox.top);
		if (distBot < minDist) {
			minDist = distBot;
			min = "bot";
		}

		// Check left
		float distLeft = abs(otherBox.left + otherBox.width - currentBox.left);
		if (distLeft < minDist) {
			minDist = distLeft;
			min = "left";
		}

		// Check right
		float distRight = abs(currentBox.left + currentBox.width - otherBox.left);
		if (distRight < minDist) {
			minDist = distRight;
			min = "right";
		}

		if (min == "top") {
			if (_vY < 0) {
				_vY *= -1;
				ChangeColor();
			}
		}
		if (min == "bot") {
			if (_vY > 0) {
				_vY *= -1;
				ChangeColor();
			}
		}

		if (min == "left") {
			if (_vX < 0) {
				_vX *= -1;
				ChangeColor();
			}
		}
		if (min == "right") {
			if (_vX > 0) {
				_vX *= -1;
				ChangeColor();
			}
		}

		return true;
	}
	return false;
}


void Ball::Move(float deltaTime)
{

	_shape->move(sf::Vector2f(_vX, _vY) * _moveSpeed * deltaTime);

}


void Ball::SetBall(sf::Vector2f pos) {

	_shape->setPosition(pos);

	_vX = 0;
	_vY = 0;
}
