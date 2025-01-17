#include "grid.h"

grid::grid(shared_ptr<class game> inst)
	:grid_h(800), grid_w(600)
{
	gameInst = inst;
}

void grid::set_grid_size(unsigned int w, unsigned int h)
{
	grid_w = w;
	grid_h = h;
}
