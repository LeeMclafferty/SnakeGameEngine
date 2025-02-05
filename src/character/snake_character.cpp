#include "snake_character.h"
#include "BodySegment.h"
#include "Head.h"
#include <memory>

snake_character::snake_character()
{
	head front;
	body.push_back(std::make_shared<class head>(front));
}


sf::Vector2i snake_character::get_position()
{
	if (body.empty()) 
		return sf::Vector2i(0, 0);

	return body[0]->get_position();
}

shared_ptr<class body_segment> snake_character::get_head()
{
	if (body.empty() || !body[0]) {
		return nullptr;
	}
	return body[0];
}

void snake_character::grow()
{
	// TODO: create new body part, set the position to the last position of the last body
	// segment in the vector, just use default constructor for body_segment.
	shared_ptr<body_segment> lastSeg = body.back();
	if (!lastSeg) return;

	body_segment part = body_segment();
	part.set_position(lastSeg->get_last_position());
	body.push_back(std::make_shared<body_segment>(part));
}

void snake_character::update(sf::RenderWindow& window)
{
	if (body.empty()) return;

	window.draw(body[0]->get_sprite());
}
