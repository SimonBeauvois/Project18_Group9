#include "Ball.h"
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

	float boxRight = currentBox.left + currentBox.width;
	float boxLeft = currentBox.left;
	float boxTop = currentBox.top;
	float boxBot = currentBox.top + currentBox.height;

	float otherBoxRight = currentBox.left + currentBox.width;
	float otherBoxLeft = currentBox.left;
	float otherBoxTop = currentBox.top;
	float otherBoxBot = currentBox.top + currentBox.height;


	if (currentBox.intersects(otherBox)) {

		if ((boxLeft <= otherBoxRight) && (boxRight >= otherBoxLeft)) {
			_vX *= -1;
			ChangeColor();
		}

		if ((boxTop <= otherBoxBot) && (otherBoxBot >= otherBoxTop)) {
			_vY *= -1;
			ChangeColor();
		}

		
	}
	
}


void Ball::Move(float deltaTime)
{
	CheckCollisionWithScreen();

	_shape->move(sf::Vector2f(_vX, _vY) * _moveSpeed * deltaTime);

}