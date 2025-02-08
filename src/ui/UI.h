#pragma once
#include <SFML/Graphics.hpp>

using std::shared_ptr;

class ui
{
public:
	ui(shared_ptr<class game> gInst);
	void update(sf::RenderWindow& window);
	void load_font();
	sf::Text get_score_text();
	void game_over(sf::RenderWindow& window);

private:
	void update_score();
	shared_ptr<class game> gameInst;
	sf::Text scoreText;
	sf::Text gameOverText;
	sf::Text restartText;
	sf::Font font;
};

