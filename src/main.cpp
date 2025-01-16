#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game Engine");
	
	sf::RectangleShape shape(sf::Vector2(20.f, 20.f));
	shape.setFillColor(sf::Color::Green);

	sf::Clock clock;
	window.setFramerateLimit(60);
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

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Scan::X) {
					window.close();
				}
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
					shape.setPosition(shape.getPosition() + sf::Vector2(0.f, 5.f));
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					shape.setPosition(shape.getPosition() + sf::Vector2(0.f, -5.f));
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					shape.setPosition(shape.getPosition() + sf::Vector2(5.f, 0.f));
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					shape.setPosition(shape.getPosition() + sf::Vector2(-5.f, 0.f));
				}
			}
		}
		

		window.setTitle("Snake Game Engine - FPS: " + std::to_string(static_cast<int>(fps)));

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}