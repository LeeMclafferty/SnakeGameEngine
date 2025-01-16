#include "game.h"
#include "../input/input_handler.h"

game::game()
{
	inputHandler = std::make_shared<input_handler>();
}
