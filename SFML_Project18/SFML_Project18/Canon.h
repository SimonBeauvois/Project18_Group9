#pragma once
#include <SFML/Graphics.hpp>

class Canon 
{
public:
	Canon(std::string lienFichier);

	void DrawCanon(sf::RenderWindow& window);

private:
	float _width;
	float _height;

	sf::Texture _texture;
	sf::Sprite *_sprite;

};

