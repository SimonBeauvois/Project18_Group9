#pragma once
#include <SFML/Graphics.hpp>



class Utils
{
public:

	static int ScreenHeight();
	static int ScreenWidth();

	static void SetPosition(sf::Shape& shape, float xCoeff, float yCoeff);

	static void SetOrigin(float anchorX, float anchorY, sf::Shape *shape);

	static float GetXR2P(float ratioX);

	static float GetYR2P(float ratioY);


private :
	static int _screenWidth;
	static int _screenHeight;
};

