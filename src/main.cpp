#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "framework/game.h"
#include "input/input_handler.h"

using std::shared_ptr;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game Engine");
	
	sf::RectangleShape shape(sf::Vector2(20.f, 20.f));
	shape.setFillColor(sf::Color::Green);

	sf::Clock clock;
	window.setFramerateLimit(60);

	shared_ptr<game> gameInstance = std::make_shared<game>();

	
	while (window.isOpen())
	{
		// Compute the frame rate
		float delta_time = clock.restart().asSeconds();
		float fps = 1.0f / (delta_time);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {;
				gameInstance->get_input_handler()->handle(event);
			}
		}
		

		window.setTitle("Snake Game Engine - FPS: " + std::to_string(static_cast<int>(fps)));

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}