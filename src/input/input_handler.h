#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

using std::shared_ptr;
class input_handler
{
public:
	enum Directions
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	input_handler(shared_ptr<class game> inst);

	void handle(sf::Event e);
	
	void move_up();
	void move_down();
	void move_left();
	void move_right();
	void continue_dir();

private:
	shared_ptr<class game> gameInst;
	shared_ptr<class snake_character> snake;
	Directions direction;
	Directions nextDir;

	
};

