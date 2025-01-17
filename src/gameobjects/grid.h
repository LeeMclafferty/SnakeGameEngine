#pragma once
#include<vector>
#include <memory>
#include <SFML/Graphics.hpp>

using std::vector;
using std::shared_ptr;

class grid
{
public:
	grid(shared_ptr<class game> inst);

	void set_grid_size(unsigned int w, unsigned int h);
	sf::Vector2i get_grid_size() { return sf::Vector2i(grid_w, grid_h); }

private:
	vector<int> play_area;
	shared_ptr<class game> gameInst;
	
	unsigned int grid_h;
	unsigned int grid_w;
};

