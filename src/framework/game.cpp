#include "game.h"
#include "../input/input_handler.h"
#include "../character/snake_character.h"
#include "../gameobjects/grid.h"
#include "../ui/UI.h"
#include <iostream>

game::game()
	:score(0), gameState(GameState::RUNNING)
{

}

void game::post_construct()
{
	inputHandler = std::make_shared<input_handler>(shared_from_this());
	snakeCharacter = std::make_shared<snake_character>(shared_from_this());
	playableGrid = std::make_shared<grid>(shared_from_this());
	if (playableGrid) {
		playableGrid->set_grid_size(300, 300);
	}

	gameUI = std::make_shared<ui>(shared_from_this());
	if (gameUI) {
		gameUI->load_font();
	}
}

void game::update(sf::RenderWindow& window)
{
	if (gameState == GameState::GAMEOVER) {
		game_over(window);
		return;
	}

	if (playableGrid) {
		playableGrid->update(window);
	}
	if (snakeCharacter) {
		snakeCharacter->update(window);
	}
	if (gameUI) {
		gameUI->update(window);
	}
}

void game::increase_score(int inc)
{
	score += inc;
}

void game::game_over(sf::RenderWindow& window)
{
	if (gameUI) {
		gameUI->game_over(window);
	}
}
