#include "input_handler.h"
#include "../framework/game.h"
#include "../character/snake_character.h"
#include <SFML/Graphics.hpp>

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
	
	sf::RectangleShape& sprite = snake->get_sprite();
	sprite.setPosition(sprite.getPosition() + sf::Vector2(0.f, -5.f));
}

void input_handler::move_down()
{
	if (!snake) return;

	sf::RectangleShape& sprite = snake->get_sprite();
	sprite.setPosition(sprite.getPosition() + sf::Vector2(0.f, 5.f));
}

void input_handler::move_left()
{
	if (!snake) return;

	sf::RectangleShape& sprite = snake->get_sprite();
	sprite.setPosition(sprite.getPosition() + sf::Vector2(-5.f, 0.f));
}

void input_handler::move_right()
{
	if (!snake) return;

	sf::RectangleShape& sprite = snake->get_sprite();
	sprite.setPosition(sprite.getPosition() + sf::Vector2(5.f, 0.f));
}
