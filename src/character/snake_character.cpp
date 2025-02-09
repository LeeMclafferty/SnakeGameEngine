#include "snake_character.h"
#include "BodySegment.h"
#include "Head.h"
#include "../framework/game.h"
#include <iostream>
#include <memory>

snake_character::snake_character(shared_ptr<class game> inst)
	:gameInst(inst)
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
	if (body.empty()) {
		std::cerr << "Error: Attempted to grow but no body segments exist!" << std::endl;
		return;
	}

	shared_ptr<body_segment> lastSeg = body.back();

	body_segment part = body_segment();
	part.set_position(lastSeg->get_last_position());
	body.push_back(std::make_shared<body_segment>(part));
}

void snake_character::update(sf::RenderWindow& window)
{
	if (body.empty()) return;
	
	int index = 0;
	for (auto segment : body) {
		// don't check for collision with the head.
		if (index > 0) {
			OnSelfCollide(segment);
		}
		window.draw(segment->get_sprite());
		++index;
	}
}

void snake_character::OnSelfCollide(shared_ptr<body_segment> segment)
{
	if (!gameInst)
		return;

	if (get_head()->get_sprite().getPosition()
		== segment->get_sprite().getPosition()) {
		if (gameInst) {
			gameInst->set_game_state(game::GAMEOVER);
		}
	}
}
