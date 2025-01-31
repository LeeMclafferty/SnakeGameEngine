#include "snake_character.h"

snake_character::snake_character()
	:sprite_width(20.f), sprite_height(20.f), sprite_color(sf::Color::Black)
{
	head.setSize(sf::Vector2(sprite_width, sprite_height));
	head.setFillColor(sprite_color);
}

void snake_character::set_position(const sf::Vector2i& pos)
{
	// Later this function will have to loop over all snake parts and update the location.
	const sf::Vector2f& fPos = static_cast<sf::Vector2f>(pos);
	head.setPosition(fPos);
	position = pos;
}

void snake_character::set_last_position(const sf::Vector2i pos)
{
	lastPosition = pos;
}

void snake_character::grow()
{
	sf::RectangleShape bodyPart = sf::RectangleShape(sf::Vector2f(sprite_width, sprite_height));
	bodyPart.setFillColor(sprite_color);
	bodyPart.setPosition(static_cast<float>(
		lastPosition.x), static_cast<float>(lastPosition.y));
	body.push_back(bodyPart);
}

void snake_character::update(sf::RenderWindow& window)
{
	window.draw(head);

	for (auto segment : body) {
		window.draw(segment);
	}
}
