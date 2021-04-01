#include "UIManager.h"
#include <string>  
#include "Utils.h"
#include <iostream>

UIManager::UIManager() 
{
	if (font.loadFromFile("FredokaOne-Regular.ttf"))
	{
		textScore.setFont(font);
		textScore.setFillColor(color);
		//textScore.setOrigin(textScore.getLocalBounds().width * 0.5, textScore.getLocalBounds().height * 0.5);
		textScore.setPosition(textSize, Utils::ScreenHeight() - textSize* 1.5);
		textScore.setCharacterSize(textSize);
		textScore.setString("Shot : "+std::to_string(compteurTir));
	}
}


void UIManager::increaseCompteurTir(float number)
{
	compteurTir += number;
	textScore.setString("Shot : " + std::to_string(compteurTir));
}


sf::Text UIManager::getTextScore()
{
	return textScore;
}


