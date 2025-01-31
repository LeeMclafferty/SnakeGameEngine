#pragma once
#include <sfml/Graphics.hpp>
#include <vector>

using std::vector;
using std::shared_ptr;

class snake_character
{
public:
	snake_character();

	shared_ptr<class body_segment> get_head();
	vector<shared_ptr<class body_segment>> get_snake() { return body; }

	void grow();
	void update(sf::RenderWindow& window);

private:
	vector<shared_ptr<class body_segment>> body;
};

