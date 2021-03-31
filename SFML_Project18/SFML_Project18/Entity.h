#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public :

	Entity();

	sf::Shape* GetShape() { return _shape; }

	void SetPosition(sf::Vector2f);

	virtual void Draw(sf::RenderWindow&);

	virtual void SetAnchors(float xAnch, float yAnch);

	virtual void ChangeColor();

protected :

	sf::Shape* _shape = nullptr;
	
};

