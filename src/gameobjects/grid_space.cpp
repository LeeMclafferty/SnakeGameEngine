#include "grid_space.h"
#include "grid.h"
#include <iostream>

using std::string;
grid_space::grid_space(shared_ptr<class grid> g, int x, int y, float width, float height,
	sf::Texture& tex)
	: owning_grid(g), position(x, y), cell_width(width), cell_height(height), texture(tex)
{
	sprite.setTexture(texture);
	//sprite.setColor(sf::Color::Blue);
	sprite.setPosition(x, y);
}
