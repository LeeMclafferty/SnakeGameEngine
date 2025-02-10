#include "SoundManager.h"
#include <iostream>
#include <filesystem>

sound_manager::sound_manager(shared_ptr<class game> g)
	:gameInst(g)
{

}

void sound_manager::play_music(std::string filePath)
{
	std::filesystem::path musicPath = std::filesystem::absolute(filePath);
	if (!music.openFromFile(musicPath.string())) {
		std::cout << "Music fail to load." << std::endl;
		return;
	}

	music.setVolume(.4f);
	music.play();
}

void sound_manager::play_sound(std::string filePath, shared_ptr<sf::SoundBuffer>& buffer, shared_ptr<sf::Sound>& sound)
{

	if (!buffer || !sound) {
		if (!buffer) buffer = std::make_shared<sf::SoundBuffer>();
		if (!sound) sound = std::make_shared<sf::Sound>();
	}

	std::filesystem::path soundPath = std::filesystem::absolute(filePath);
	if (!buffer->loadFromFile(soundPath.string())) {
		std::cout << "sound fail to load." << std::endl;
		return;
	}

	sound->setBuffer(*buffer);
	sound->setVolume(1);
	sound->play();
}
