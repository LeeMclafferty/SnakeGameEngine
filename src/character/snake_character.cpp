#include "snake_character.h"

snake_character::snake_character()
	:sprite_width(20.f), sprite_height(20.f), sprite_color(sf::Color::Black)
{
	sprite.setSize(sf::Vector2(sprite_width, sprite_height));
	sprite.setFillColor(sprite_color);
}
