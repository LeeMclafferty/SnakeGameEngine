#include "grid_space.h"
#include "grid.h"

grid_space::grid_space(shared_ptr<class grid> g)
{
	owning_grid = g;
	if (g) {
		space_size = g->get_grid_slot_size();
	}
}