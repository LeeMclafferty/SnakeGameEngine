#pragma once
#include <memory>

using std::shared_ptr;

class game : public std::enable_shared_from_this<game>
{
public:
	game();
	void post_construct();
	void update();

	shared_ptr<class input_handler> get_input_handler() { return inputHandler; }
	shared_ptr<class snake_character> get_snake_character() { return snakeCharacter; }
	shared_ptr<class grid> get_grid() { return playableGrid; }

private:
	shared_ptr<class input_handler> inputHandler;
	shared_ptr<class snake_character> snakeCharacter;
	shared_ptr<class grid> playableGrid;
};

