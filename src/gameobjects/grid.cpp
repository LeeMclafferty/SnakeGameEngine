#include "grid.h"

grid::grid(shared_ptr<class game> inst)
	:grid_h(800), grid_w(600), grid_space_h(20.f)
{
	gameInst = inst;
}

void grid::set_grid_size(unsigned int w, unsigned int h)
{
	grid_w = w;
	grid_h = h;
}

unsigned int grid::get_grid_slot_size()
{
	return grid_h / grid_space_h;
}

void grid::post_construct()
{
	for (int i = 0; i <= grid_h; ++i) {
		for (int j = 0; j <= grid_w; ++j) {
			// Create new space.
		}
	}
}
