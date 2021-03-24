#pragma once


#include <SFML/System/Vector2.hpp>

class math
{
public:
	static void Normalize(sf::Vector2f&);

	static float Distance(sf::Vector2f, sf::Vector2f);
};

