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
