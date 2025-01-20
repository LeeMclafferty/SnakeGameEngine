#pragma once
#include <memory>

using std::shared_ptr;

class grid_space
{
public:
	grid_space(shared_ptr<class grid> g);

	int width;
	int height;

private:
	shared_ptr<class grid> owning_grid;
};

