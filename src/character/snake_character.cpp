#include "snake_character.h"
#include "BodySegment.h"
#include "Head.h"
#include <memory>

snake_character::snake_character()
{
	head front;
	body.push_back(std::make_shared<class head>(front));
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
	
// 	sf::RectangleShape bodyPart = sf::RectangleShape(sf::Vector2f(sprite_width, sprite_height));
// 	bodyPart.setFillColor(sprite_color);
// 	body.push_back(bodyPart);
}

void snake_character::update(sf::RenderWindow& window)
{
	if (body.empty()) return;

	window.draw(body[0]->get_sprite());
// 	sf::Vector2i lp = lastHeadPos;
// 
// 	for (auto segment : body) {
// 		segment.setPosition(static_cast<float>(lastHeadPos.x),
// 			static_cast<float>(lastHeadPos.y));
// 		window.draw(segment);
// 	}
}
