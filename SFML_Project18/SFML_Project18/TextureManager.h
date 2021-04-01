#pragma once
#include <SFML/Graphics.hpp>

class TextureManager
{
public:
	static sf::Texture* _texture;
	static sf::Texture* _texture2;
	static sf::Texture* _texture3;

	static sf::Texture _textureFond;

	static std::string lienTexture;
	static std::string lienTexture2;
	static std::string lienTexture3;

	static std::string lienTextureFond;

	void static loadTexture();
};

