#pragma once
#include <SFML/Audio.hpp>

using std::shared_ptr;

class sound_manager
{
public:
	sound_manager(shared_ptr<class game> g);
	void play_music(std::string filePath);

private:
	shared_ptr<class game> gameInst;
	sf::Music music;
};

