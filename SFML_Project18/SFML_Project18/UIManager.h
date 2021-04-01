#pragma once
#include <SFML/Graphics.hpp>

class UIManager
{
private:
	int compteurTir = 0;
	int textSize = 30;
	sf::Font font;
	sf::Text textScore;
	sf::Color color = sf::Color(46, 204, 113, 255);
public : 
	UIManager();
	void increaseCompteurTir(float number);
	sf::Text getTextScore();
};

