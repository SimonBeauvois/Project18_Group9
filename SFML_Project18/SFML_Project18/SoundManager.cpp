#include "SoundManager.h"

SoundManager::SoundManager() 
{
	if (buffer_explosion.loadFromFile("explosion_sound.wav")) 
	{
		sound_explosion.setBuffer(buffer_explosion);
	}
	if (buffer_shot.loadFromFile("shot_sound.wav"))
	{
		sound_shot.setBuffer(buffer_shot);
	}
}

void SoundManager::playExplosionSound()
{
	sound_explosion.play();
	sound_explosion.setVolume(12);
}

void SoundManager::playShotSound()
{
	sound_shot.play();
	sound_shot.setVolume(12);
}

void SoundManager::playMusic()
{
	if (music.openFromFile("musique_sound.ogg"))
	{ 
		music.play(); 
		music.setLoop(true);
		music.setVolume(10);
	}
}

