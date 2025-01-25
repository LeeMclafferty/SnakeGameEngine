#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

using std::shared_ptr;

class grid_space {
public:
	grid_space(shared_ptr<class grid> g ,int x, int y, float width, float height);

	sf::Vector2i get_position() const { return position; }
	sf::FloatRect get_bounds() const {
		return sf::FloatRect(position.x, position.y, cell_width, cell_height);
	}

private:
	shared_ptr<class grid> owning_grid;
	sf::Vector2i position; // Top-left corner of the cell
	float cell_width, cell_height; // Dimensions of the cell
};


