#include "grid.h"

grid::grid(shared_ptr<class game> inst)
	:gameInst(inst), gridHeight(600), gridWidth(600), cellSize(20)
{
}

void grid::set_grid_size(unsigned int w, unsigned int h)
{
	gridWidth = w;
	gridHeight = h;
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

void grid::populate_grid()
{
	play_area.clear();

	int rows = row_count();
	int cols = col_count();

	for (int y = 0; y < rows; ++y) {
		std::vector<grid_space> row;
		for (int x = 0; x < cols; ++x) {
			row.emplace_back(grid_space(shared_from_this(), x * cellSize, y * cellSize, cellSize, cellSize));
		}
		play_area.push_back(row);
	}
}