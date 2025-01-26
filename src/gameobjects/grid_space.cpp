#include "grid_space.h"
#include "grid.h"
#include <iostream>

grid_space::grid_space(shared_ptr<class grid> g, int x, int y, float width, float height) 
	: owning_grid(g), position(x, y), cell_width(width), cell_height(height)
{
	sprite = sf::IntRect(x, y, width, height);
	init_texture();
}

void grid_space::init_texture()
{
	try {
		if (!texture.loadFromFile("../Assets/grid_texture.png")) {
			throw std::runtime_error("Failed to load texture from ../Assets/grid_texture.png");
		}
	}
	catch(std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
