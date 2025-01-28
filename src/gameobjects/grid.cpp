#include "grid.h"
#include <iostream>
#include <filesystem>

using std::string;

grid::grid(shared_ptr<class game> inst)
	:gameInst(inst), gridHeight(600), gridWidth(600), cellSize(20)
{
}

void grid::set_grid_size(unsigned int w, unsigned int h)
{
	gridWidth = w;
	gridHeight = h;
	init_textures();
	populate_grid();
}

sf::Vector2i grid::get_grid_size()
{
	return sf::Vector2i(gridWidth, gridHeight);
}

int grid::row_count()
{
	return gridHeight / cellSize;
}

int grid::col_count()
{
	return gridWidth / cellSize;
}

void grid::update(sf::RenderWindow& window)
{
	int rows = row_count();
	int cols = col_count();

	// Loop over all spaces and draw.
	for (int y = 0; y < rows; ++y) {
		for (int x = 0; x < cols; ++x) {
			grid_space& space = play_area[x][y];
			window.draw(space.get_sprite());
			std::cout << "Sprite Drawn at at: x - " << space.get_position().x << " y - " << space.get_position().y << std::endl;
		}
	}
}

void grid::populate_grid()
{
	play_area.clear();

	int rows = row_count();
	int cols = col_count();


	for (int y = 0; y < rows; ++y) {
		std::vector<grid_space> row;
		for (int x = 0; x < cols; ++x) {
			grid_space space(shared_from_this(), x * cellSize, y * cellSize, cellSize, 
				cellSize, grid_space_texture);
			//std::cout << "Space Created at: x - " << x * cellSize << " y - " << y * cellSize << std::endl;
			row.emplace_back(space);
		}
		play_area.push_back(row);
	}
}

void grid::init_textures()
{
	string path = "Assets/grid_texture.png";
	std::filesystem::path absolutePath = std::filesystem::absolute(path);

	try {
		if (!grid_space_texture.loadFromFile(absolutePath.string())) {
			throw std::runtime_error("Failed to load texture from " + absolutePath.string());
		}
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "Texture loaded successfully." << std::endl;
}
