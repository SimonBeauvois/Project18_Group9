#include "Ball.h"
#include <math.h>
#include "Utils.h"

Ball::Ball(float radius) {

	_radius = radius;
	_shape = new sf::CircleShape(_radius);
}

void Ball::CheckCollisionWithScreen() {

	sf::FloatRect currentBox = _shape->getGlobalBounds();

	if (currentBox.left + _vX < 0) {
		_vX *= -1;
		ChangeColor();
	}

	if (currentBox.top + _vY < 0) {
		_vY *= -1;
		ChangeColor();
	}
	if (currentBox.left + currentBox.width + _vX > Utils::ScreenWidth()) {
		_vX *= -1;
		ChangeColor();
	}
	if (currentBox.top + currentBox.height + _vY > Utils::ScreenHeight()) {
		_vY *= -1;
		ChangeColor();
	}
}

void Ball::CheckCollisionWithEntity(Entity* entity)
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

	if (currentBox.intersects(otherBox) && _isOut) {

		std::string min;


		// Check top
		float distTop = abs(otherBox.top + otherBox.height - currentBox.top);
		float minDist = distTop;
		min = "top";

		// Check bot
		float distBot = abs(currentBox.top + currentBox.height - otherBox.top );
		if (distBot < minDist) {
			minDist = distBot;
			min = "bot";
		}

		// Check left
		float distLeft = abs(otherBox.left + otherBox.width - currentBox.left );
		if (distLeft < minDist) {
			minDist = distLeft;
			min = "left";
		}

		// Check right
		float distRight = abs(currentBox.left + currentBox.width  - otherBox.left);
		if (distRight < minDist) {
			minDist = distRight;
			min = "right";
		}

		if (min == "top" || min == "bot") {
			_vY *= -1;
			ChangeColor();
		}

		if (min == "left" || min == "right") {
			_vX *= -1;
			ChangeColor();
		}

		_isOut = false;

	}

	if(!currentBox.intersects(otherBox)){
		_isOut = true;
	}
}


void Ball::Move(float deltaTime)
{
	CheckCollisionWithScreen();

	_shape->move(sf::Vector2f(_vX, _vY) * _moveSpeed * deltaTime);

}