#include "grid_space.h"
#include "grid.h"
#include <iostream>

using std::string;
grid_space::grid_space(shared_ptr<class grid> g, int x, int y, int width, int height,
	sf::Texture& tex)
	: owning_grid(g), position(x, y), cell_width(width), cell_height(height), texture(tex)
{
	sprite.setTexture(texture);
	//sprite.setColor(sf::Color::Blue);
	sprite.setPosition(x, y);
}

sf::FloatRect grid_space::get_bounds() const
{
	return sf::FloatRect(
		static_cast<float>(position.x),
		static_cast<float>(position.y),
		static_cast<float>(cell_width),
		static_cast<float>(cell_height)
	);
}
