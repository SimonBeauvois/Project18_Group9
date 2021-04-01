#pragma once
#include <SFML/Audio.hpp>

class SoundManager
{
private:
	sf::SoundBuffer buffer_explosion;
	sf::Sound sound_explosion;

	sf::SoundBuffer buffer_shot;
	sf::Sound sound_shot;

	sf::Music music;

public: 
	SoundManager();
	void playExplosionSound();
	void playShotSound();
	void playMusic();
};

