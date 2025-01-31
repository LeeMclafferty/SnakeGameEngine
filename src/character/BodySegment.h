#pragma once
#include <SFML/Graphics.hpp>

class body_segment
{
public:
	body_segment();
	body_segment(float w, float h, sf::Color c);

	sf::RectangleShape& get_sprite() { return segment; }
	sf::Color get_sprite_color() { return sprite_color; } 
	sf::Vector2i get_position() { return position; }
	sf::Vector2i get_last_position() { return lastPos; }
	float get_sprite_w() { return sprite_width; }
	float get_sprite_h() { return sprite_height; }

	void set_position(sf::Vector2i p);
private:
	sf::RectangleShape segment;
	float sprite_width;
	float sprite_height;
	sf::Color sprite_color;
	sf::Vector2i position;
	sf::Vector2i lastPos;
};

