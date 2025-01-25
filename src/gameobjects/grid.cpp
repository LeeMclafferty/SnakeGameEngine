#include "grid.h"

grid::grid(shared_ptr<class game> inst)
	:gameInst(inst), grid_h(800), grid_w(600)
{

}

void grid::set_grid_size(unsigned int w, unsigned int h)
{
	grid_w = w;
	grid_h = h;
	populate_grid();
}

sf::Vector2i grid::get_grid_size()
{
	return sf::Vector2i(grid_w, grid_h);
}

void grid::populate_grid()
{
	play_area.clear();

	const int cell_size = 20;
	int rows = grid_h / cell_size;
	int cols = grid_w / cell_size;

	for (int y = 0; y < rows; ++y) {
		std::vector<grid_space> row;
		for (int x = 0; x < cols; ++x) {
			row.emplace_back(shared_from_this(), x * cell_size, y * cell_size, cell_size, cell_size);
		}
		play_area.push_back(row);
	}
}
