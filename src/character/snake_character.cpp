#include "snake_character.h"

snake_character::snake_character()
	:sprite_width(20.f), sprite_height(20.f), sprite_color(sf::Color::Black)
{
	sprite.setSize(sf::Vector2(sprite_width, sprite_height));
	sprite.setFillColor(sprite_color);
}

void snake_character::set_position(const sf::Vector2i& pos)
{
	// Later this function will have to loop over all snake parts and update the location.
	const sf::Vector2f& fPos = static_cast<sf::Vector2f>(pos);
	sprite.setPosition(fPos);
	position = pos;
}
