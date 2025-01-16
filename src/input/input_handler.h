#pragma once
#include <SFML/Graphics.hpp>

class input_handler
{
public:
	input_handler();

	void handle(sf::Event e);
	
	void move_up();
	void move_down();
	void move_left();
	void move_right();

private:
	
};

