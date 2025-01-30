#pragma once
#include <SFML/Graphics.hpp>

using std::shared_ptr;

class ui
{
public:
	ui(shared_ptr<class game> gInst);
	void load_font();
	sf::Text get_score_text();

private:

	void update_score();
	shared_ptr<class game> gameInst;
	sf::Text scoreText;
	sf::Font font;
};

