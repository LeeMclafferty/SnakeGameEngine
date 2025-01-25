#pragma once
#include <sfml/Graphics.hpp>

class snake_character
{
public:
	snake_character();

	sf::RectangleShape& get_sprite() { return sprite; }

	float get_sprite_w() { return sprite_width; }
	float get_sprite_h() { return sprite_height; }
	sf::Color get_sprite_color() { return sprite_color; }
	sf::Vector2i get_position() { return position; }

	void set_position(const sf::Vector2i& pos);

private:
	sf::RectangleShape sprite;
	float sprite_width;
	float sprite_height;
	sf::Color sprite_color;

	sf::Vector2i position;

};

