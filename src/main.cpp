#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "framework/game.h"
#include "input/input_handler.h"
#include "character/snake_character.h"
#include "gameobjects/grid.h"

using std::shared_ptr;

int main()
{

	unsigned int window_w = 800;
	unsigned int window_h = 600;
	unsigned int frame_rate = 60;
	sf::RenderWindow window(sf::VideoMode(window_w, window_h), "Snake Game Engine");
	window.setFramerateLimit(frame_rate);
	
	sf::Clock clock;

	shared_ptr<game> gameInstance = std::make_shared<game>();
	gameInstance->post_construct();

	shared_ptr<snake_character> snake = gameInstance->get_snake_character();

	while (window.isOpen())
	{
		if (!gameInstance) break;

		// Compute the frame rate
		float delta_time = clock.restart().asSeconds();
		float fps = 1.0f / (delta_time);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {
				gameInstance->get_input_handler()->handle(event);
			}

			if (event.type == sf::Event::Resized)
			{
				// update the view to the new size of the window
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));

				// change grid size with window size
				gameInstance->get_grid()->set_grid_size(visibleArea.width, visibleArea.height);
			}
		}

		window.setTitle("Snake Game Engine - FPS: " + std::to_string(static_cast<int>(fps)));

		window.clear(sf::Color(209, 220, 59, 255));
		window.draw(snake->get_sprite());
		window.display();

		//std::cout << gameInstance->get_grid()->get_grid_size().x << std::endl; 
	}

	return 0;
}