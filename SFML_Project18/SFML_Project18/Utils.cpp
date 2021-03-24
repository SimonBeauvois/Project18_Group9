#include "Utils.h"

int Utils::_screenHeight = 800;
int Utils::_screenWidth = 600;

int Utils::ScreenHeight()
{
	return _screenHeight;
}

int Utils::ScreenWidth()
{
	return _screenWidth;
}

void Utils::SetPosition(sf::Shape& shape, float xCoeff, float yCoeff)
{

	shape.setPosition(xCoeff * ScreenWidth(), yCoeff * ScreenHeight());
}

float Utils::GetXR2P(float ratioX) { return ratioX * ScreenWidth(); }

float Utils::GetYR2P(float ratioY){  return ratioY * ScreenWidth(); }

void Utils::SetOrigin(float anchorX, float anchorY, sf::Shape *shape)
{
	float width = shape->getLocalBounds().width;
	float height = shape->getLocalBounds().height;

	shape->setOrigin(width * anchorX, height * anchorY);
}



