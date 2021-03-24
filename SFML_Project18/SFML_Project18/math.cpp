#include "math.h"
#include <math.h>

void math::Normalize(sf::Vector2f& vect)
{
	float norm = sqrt(vect.x * vect.x + vect.y * vect.y);

	vect.x = vect.x / norm;
	vect.y = vect.y / norm;


}

float math::Distance(sf::Vector2f a, sf::Vector2f b)
{
	return sqrt((b.x-a.x)* (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
