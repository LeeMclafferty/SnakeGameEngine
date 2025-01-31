#pragma once
#include <sfml/Graphics.hpp>
#include <vector>

class snake_character
{
public:
	snake_character();

	sf::RectangleShape& get_head_sprite() { return head; }

	float get_sprite_w() { return sprite_width; }
	float get_sprite_h() { return sprite_height; }
	sf::Color get_sprite_color() { return sprite_color; }
	sf::Vector2i get_position() { return position; }

	void set_position(const sf::Vector2i& pos);
	void set_last_position(const sf::Vector2i pos);
	void grow();
	void update(sf::RenderWindow& window);

private:
	sf::RectangleShape head;
	std::vector<sf::RectangleShape> body;
	float sprite_width;
	float sprite_height;
	sf::Color sprite_color;

	sf::Vector2i position;
	sf::Vector2i lastPosition;

};

