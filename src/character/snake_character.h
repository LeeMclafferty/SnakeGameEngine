#pragma once
#include <sfml/Graphics.hpp>
#include <vector>
#include "../sound/SoundManager.h"

using std::vector;
using std::shared_ptr;

class snake_character
{
public:
	snake_character(shared_ptr<class game> inst);

	// Return the head's position as the snakes position.
	sf::Vector2i get_position();
	shared_ptr<class body_segment> get_head();
	vector<shared_ptr<class body_segment>> get_snake() { return body; }

	void grow();
	void update(sf::RenderWindow& window);
	void play_beep();
	void play_chomp();

private:
	vector<shared_ptr<class body_segment>> body;
	shared_ptr<class game> gameInst;
	
	sound_manager soundManager;

	shared_ptr<sf::SoundBuffer> beepBuffer;
	shared_ptr<sf::Sound> beepSound;

	shared_ptr<sf::SoundBuffer> chompBuffer;
	shared_ptr<sf::Sound> chompSound;

	
	void OnSelfCollide(shared_ptr<body_segment> segment);
};

