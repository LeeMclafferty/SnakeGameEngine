#include "input_handler.h"

input_handler::input_handler()
{

}

void input_handler::handle(sf::Event e)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		move_down();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		move_up();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		move_right;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		move_left();
	}
}

void input_handler::move_up()
{
	shape.setPosition(shape.getPosition() + sf::Vector2(0.f, -5.f));
}

void input_handler::move_down()
{
	shape.setPosition(shape.getPosition() + sf::Vector2(0.f, 5.f));
}

void input_handler::move_left()
{
	shape.setPosition(shape.getPosition() + sf::Vector2(-5.f, 0.f));
}

void input_handler::move_right()
{
	shape.setPosition(shape.getPosition() + sf::Vector2(5.f, 0.f));
}
