#pragma once
#include "Entity.h"

class Canon : public Entity
{
public:
	Canon(float, float);

	void DrawCanon(sf::RenderWindow& window);


private:
	
	float _width;
	float _height;

};

