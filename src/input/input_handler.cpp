#include "input_handler.h"
#include "../framework/game.h"
#include "../character/snake_character.h"
#include "../character/BodySegment.h"
#include "../gameobjects/grid.h"
#include <SFML/Graphics.hpp>
#include <iostream>

input_handler::input_handler(shared_ptr<game> inst)
{
	gameInst = inst;
	direction = RIGHT;
}

void input_handler::handle(sf::Event e)
{
	snake = gameInst->get_snake_character();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		nextDir = DOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		nextDir = UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		nextDir = RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		nextDir = LEFT;
	}
}

void input_handler::move_up()
{
	if (!snake) return;

	sf::Vector2i current_head_grid = {
		static_cast<int>(snake->get_position().x / 20),
		static_cast<int>(snake->get_position().y / 20)
	};

	sf::Vector2i target_head_grid = current_head_grid;
	target_head_grid.y -= 1;

	sf::Vector2i target_head_pos = {
		target_head_grid.x * 20,
		target_head_grid.y * 20
	};

	if (snake->get_snake().size() > 1)
	{
		// Stops at 1 to avoid moving the head until loop is done. 
		for (int i = snake->get_snake().size() - 1; i > 0; --i) {
			const auto& body = snake->get_snake();
			body[i]->set_position(body[i - 1]->get_position());
		}
	}

	if (target_head_grid.y >= 0) {
		snake->get_head()->set_position(target_head_pos);
	}
}


void input_handler::move_down()
{
	if (!snake) return;

	sf::Vector2i current_head_grid = {
		static_cast<int>(snake->get_position().x / 20),
		static_cast<int>(snake->get_position().y / 20)
	};

	sf::Vector2i target_head_grid = current_head_grid;
	target_head_grid.y += 1;

	sf::Vector2i target_head_pos = {
		target_head_grid.x * 20,
		target_head_grid.y * 20
	};

	if (snake->get_snake().size() > 1)
	{
		// Stops at 1 to avoid moving the head until loop is done. 
		for (int i = snake->get_snake().size() - 1; i > 0; --i) {
			const auto& body = snake->get_snake();
			body[i]->set_position(body[i - 1]->get_position());
		}
	}

	if (target_head_grid.y <= gameInst->get_grid()->row_count() - 1) {
		snake->get_head()->set_position(target_head_pos);
	}
}

void input_handler::move_left()
{
	if (!snake) return;

	sf::Vector2i current_head_grid = {
		static_cast<int>(snake->get_position().x / 20),
		static_cast<int>(snake->get_position().y / 20)
	};

	sf::Vector2i target_head_grid = current_head_grid;
	target_head_grid.x -= 1;

	sf::Vector2i target_head_pos = {
		target_head_grid.x * 20,
		target_head_grid.y * 20
	};

	if (snake->get_snake().size() > 1)
	{
		// Stops at 1 to avoid moving the head until loop is done. 
		for (int i = snake->get_snake().size() - 1; i > 0; --i) {
			const auto& body = snake->get_snake();
			body[i]->set_position(body[i - 1]->get_position());
		}
	}

	if (target_head_grid.x >= 0) {
		snake->get_head()->set_position(target_head_pos);
	}
}

void input_handler::move_right()
{
	if (!snake) return;

	sf::Vector2i current_head_grid = {
		static_cast<int>(snake->get_position().x / 20),
		static_cast<int>(snake->get_position().y / 20)
	};

	sf::Vector2i target_head_grid = current_head_grid;
	target_head_grid.x += 1;

	sf::Vector2i target_head_pos = {
		target_head_grid.x * 20,
		target_head_grid.y * 20
	};

	if (snake->get_snake().size() > 1)
	{
		// Stops at 1 to avoid moving the head until loop is done. 
		for (int i = snake->get_snake().size() - 1; i > 0; --i) {
			const auto& body = snake->get_snake();
			body[i]->set_position(body[i - 1]->get_position());
		}
	}

	if (target_head_grid.x <= gameInst->get_grid()->col_count() - 1) {
		snake->get_head()->set_position(target_head_pos);
	}
}

void input_handler::continue_dir()
{
	direction = nextDir;

	switch (direction)
	{
	case input_handler::UP:
		move_up();
		break;
	case input_handler::DOWN:
		move_down();
		break;
	case input_handler::LEFT:
		move_left();
		break;
	case input_handler::RIGHT:
		move_right();
		break;
	default:
		break;
	}
}
