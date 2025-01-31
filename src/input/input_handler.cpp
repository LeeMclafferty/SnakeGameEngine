#include "input_handler.h"
#include "../framework/game.h"
#include "../character/snake_character.h"
#include "../gameobjects/grid.h"
#include <SFML/Graphics.hpp>
#include <iostream>

input_handler::input_handler(shared_ptr<game> inst)
{
	gameInst = inst;
}

void input_handler::handle(sf::Event e)
{
	snake = gameInst->get_snake_character();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		move_down();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		move_up();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		move_right();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		move_left();
	}
}

void input_handler::move_up()
{
	if (!snake) return;

	sf::Vector2i current_grid = {
		static_cast<int>(snake->get_position().x / 20),
		static_cast<int>(snake->get_position().y / 20)
	};

	sf::Vector2i target_grid = current_grid;
	target_grid.y -= 1;

	sf::Vector2i target_position = {
		target_grid.x * 20,
		target_grid.y * 20
	};

// 	std::cout << "Target X: " << target_grid.x << std::endl;
// 	std::cout << "Target Y: " << target_grid.y << std::endl;

	if (target_grid.y >= 0) {
		snake->set_last_position(snake->get_position());
		snake->set_position(target_position);
	}
}


void input_handler::move_down()
{
	if (!snake) return;

	sf::Vector2i current_grid = {
		static_cast<int>(snake->get_position().x / 20),
		static_cast<int>(snake->get_position().y / 20)
	};

	sf::Vector2i target_grid = current_grid;
	target_grid.y += 1;

	sf::Vector2i target_position = {
		target_grid.x * 20,
		target_grid.y * 20
	};

	//std::cout << "Target X: " << target_grid.x << std::endl;
	//std::cout << "Target Y: " << target_grid.y << std::endl;

	if (target_grid.y <= gameInst->get_grid()->row_count() - 1) {
		snake->set_last_position(snake->get_position());
		snake->set_position(target_position);
	}
}

void input_handler::move_left()
{
	if (!snake) return;

	sf::Vector2i current_grid = {
		static_cast<int>(snake->get_position().x / 20),
		static_cast<int>(snake->get_position().y / 20)
	};



	sf::Vector2i target_grid = current_grid;
	target_grid.x -= 1;

	sf::Vector2i target_position = {
		target_grid.x * 20,
		target_grid.y * 20
	};

// 	std::cout << "Target X: " << target_grid.x << std::endl;
// 	std::cout << "Target Y: " << target_grid.y << std::endl;

	if (target_grid.x >= 0) {
		snake->set_last_position(snake->get_position());
		snake->set_position(target_position);
	}
}

void input_handler::move_right()
{
	if (!snake) return;

	sf::Vector2i current_grid = {
		static_cast<int>(snake->get_position().x / 20),
		static_cast<int>(snake->get_position().y / 20)
	};

	sf::Vector2i target_grid = current_grid;
	target_grid.x += 1;

	sf::Vector2i target_position = {
		target_grid.x * 20,
		target_grid.y * 20
	};

// 	std::cout << "Target X: " << target_grid.x << std::endl;
// 	std::cout << "Target Y: " << target_grid.y << std::endl;

	if (target_grid.x <= gameInst->get_grid()->col_count() - 1) {
		snake->set_last_position(snake->get_position());
		snake->set_position(target_position);
	}
}