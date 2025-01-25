#pragma once
#include<vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "grid_space.h"

using std::shared_ptr;

class grid : public std::enable_shared_from_this<grid>
{
public:
	grid(shared_ptr<class game> inst);

	void set_grid_size(unsigned int w, unsigned int h);
	sf::Vector2i get_grid_size();

	int row_count();
	int col_count();

	const int cellSize;

private:
	void populate_grid();

	std::vector<std::vector<grid_space>> play_area;
	shared_ptr<class game> gameInst;

	unsigned int gridHeight;
	unsigned int gridWidth;

};

