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

	unsigned int window_w = 500;
	unsigned int window_h = 310;
	unsigned int frame_rate = 60;
	sf::RenderWindow window(sf::VideoMode(window_w, window_h), "Snake Game Engine");
	window.setFramerateLimit(frame_rate);
	
	sf::Clock clock;
	sf::Clock moveClock;
	const float moveInterval = 0.1f;

	shared_ptr<game> gameInstance = std::make_shared<game>();
	gameInstance->post_construct();

	shared_ptr<snake_character> snake = gameInstance->get_snake_character();

	while (window.isOpen())
	{
		if (!gameInstance) break;

		// Compute the frame rate
		float deltaTime = clock.restart().asSeconds();
		float fps = 1.0f / (deltaTime);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {
				gameInstance->get_input_handler()->handle(event);
			}
		}

		// Move the snake at a fixed interval
		if (moveClock.getElapsedTime().asSeconds() >= moveInterval)
		{
			gameInstance->get_input_handler()->continue_dir();
			moveClock.restart();
		}

		window.setTitle("Snake Game Engine - FPS: " + std::to_string(static_cast<int>(fps)));

		window.clear(sf::Color(sf::Color(150,150,150)));
		gameInstance->update(window);
		window.display();
	}

	return 0;
}