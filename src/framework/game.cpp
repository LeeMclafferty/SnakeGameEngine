#include "game.h"
#include "../input/input_handler.h"
#include "../character/snake_character.h"
#include "../gameobjects/grid.h"

game::game()
{

}

void game::post_construct()
{
	inputHandler = std::make_shared<input_handler>(shared_from_this());
	snakeCharacter = std::make_shared<snake_character>();
	playableGrid = std::make_shared<grid>(shared_from_this());
}

void game::update()
{

}
