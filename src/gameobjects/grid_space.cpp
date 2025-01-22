#include "grid_space.h"
#include "grid.h"

grid_space::grid_space(shared_ptr<class grid> g, int x, int y, float width, float height) 
	: owning_grid(g), position(x, y), cell_width(width), cell_height(height)
{

}
