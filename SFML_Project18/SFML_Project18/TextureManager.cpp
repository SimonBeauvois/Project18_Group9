#include "TextureManager.h"

sf::Texture* TextureManager::_texture = nullptr;
sf::Texture* TextureManager::_texture2 = nullptr;
sf::Texture* TextureManager::_texture3 = nullptr;
sf::Texture TextureManager::_textureFond;

std::string TextureManager::lienTexture = "brique_texture_alien.jpg";
std::string TextureManager::lienTexture2 = "brique_texture_alien2.jpg";
std::string TextureManager::lienTexture3 = "brique_texture_alien3.jpg";
std::string TextureManager::lienTextureFond = "plage-cartoon2.jpg";

void TextureManager::loadTexture()
{
	_texture = new sf::Texture();
	_texture2 = new sf::Texture();
	_texture3 = new sf::Texture();

 	if (_texture->loadFromFile(lienTexture) && _texture2->loadFromFile(lienTexture2) && _texture3->loadFromFile(lienTexture3)) //si le lien est fonctionnel
	{
		_texture->setSmooth(true);
		_texture2->setSmooth(true);
		_texture3->setSmooth(true);
	}
	if (_textureFond.loadFromFile(lienTextureFond))
	{
		_textureFond.setSmooth(true);
	}
}
