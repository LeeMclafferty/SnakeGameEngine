#pragma once
#include <SFML/Audio.hpp>

using std::shared_ptr;

class sound_manager
{
public:
	sound_manager(shared_ptr<class game> g);
	void play_music(std::string filePath);
	void play_sound(std::string filePath, shared_ptr<sf::SoundBuffer>& buffer, shared_ptr<sf::Sound>& sound);

private:
	shared_ptr<class game> gameInst;
	sf::Music music;

};

