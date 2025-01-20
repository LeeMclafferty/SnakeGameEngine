#include "grid_space.h"

grid_space::grid_space(shared_ptr<class grid> g)
	:height(0), width(0)
{
	owning_grid = g;
}
