#include "game.h"
#include "../input/input_handler.h"
#include "../character/snake_character.h"
#include "../gameobjects/grid.h"
#include <iostream>

game::game()
	:score(0)
{

}

void game::post_construct()
{
	inputHandler = std::make_shared<input_handler>(shared_from_this());
	snakeCharacter = std::make_shared<snake_character>();
	playableGrid = std::make_shared<grid>(shared_from_this());
	if (playableGrid) {
		playableGrid->set_grid_size(600, 600);
	}
}

void game::update(sf::RenderWindow& window)
{
	if (playableGrid) {
		playableGrid->update(window);
	}
	if (snakeCharacter) {
		window.draw(snakeCharacter->get_sprite());
		//std::cout << "Snake x: " << snakeCharacter->get_position().x << " Snake y: " << snakeCharacter->get_position().y<<  std::endl;
	}
}

void game::increase_score(int inc)
{
	score += inc;
}
