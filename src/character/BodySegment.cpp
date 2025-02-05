#include "BodySegment.h"

body_segment::body_segment()
	:sprite_width(20.f), sprite_height(20.f), sprite_color(sf::Color::Black)
{
	position = sf::Vector2i(0.f, 0.f);
	segment.setPosition(static_cast<sf::Vector2f>(position));
	segment.setSize(sf::Vector2(sprite_width, sprite_height));
	segment.setFillColor(sprite_color);
}

body_segment::body_segment(float w, float h, sf::Color c)
	:sprite_width(w), sprite_height(h), sprite_color(c)
{
	segment.setSize(sf::Vector2(sprite_width, sprite_height));
	segment.setFillColor(sprite_color);
}

void body_segment::set_position(sf::Vector2i p)
{
	lastPos = position;
	position = p;
	segment.setPosition(static_cast<sf::Vector2f>(p));
}
