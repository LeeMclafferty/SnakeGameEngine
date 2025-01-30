#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

using std::shared_ptr;

class grid_space {
public:
	grid_space(shared_ptr<class grid> g, int x, int y, int width, int height
	, sf::Texture& tex);

	const sf::Sprite& get_sprite() { return sprite; }
	sf::Vector2i get_position() const { return position; }
	sf::FloatRect get_bounds() const;

private:
	sf::Sprite sprite;
	const sf::Texture& texture;
	shared_ptr<class grid> owning_grid;
	sf::Vector2i position; // Top-left corner of the cell
	float cell_width, cell_height; // Dimensions of the cell
	
};


