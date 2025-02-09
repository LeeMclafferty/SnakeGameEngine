#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

using std::shared_ptr;

class game : public std::enable_shared_from_this<game>
{
public:
	enum GameState
	{
		RUNNING,
		GAMEOVER,
		RESTART
	};

	game();
	void post_construct();
	void update(sf::RenderWindow& window);

	shared_ptr<class input_handler> get_input_handler() { return inputHandler; }
	shared_ptr<class snake_character> get_snake_character() { return snakeCharacter; }
	shared_ptr<class grid> get_grid() { return playableGrid; }

	void increase_score(int inc);
	int get_score() { return score; }

	void set_game_state(GameState newState) { gameState = newState; }
	const GameState& get_game_state() const { return gameState; }

private:
	shared_ptr<class input_handler> inputHandler;
	shared_ptr<class snake_character> snakeCharacter;
	shared_ptr<class grid> playableGrid;
	shared_ptr<class ui> gameUI;
	shared_ptr<class sound_manager> soundManager;
	
	int score;
	GameState gameState;

	void game_over(sf::RenderWindow& window);
	void restart_game();
};

