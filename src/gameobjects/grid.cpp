#include "grid.h"
#include "../character/snake_character.h"
#include "../framework/game.h"
#include <iostream>
#include <filesystem>
#include <random>

using std::string;

grid::grid(shared_ptr<class game> inst)
	:gameInst(inst), gridHeight(600), gridWidth(600), cellSize(20), mouse(nullptr)
{
}

void grid::set_grid_size(unsigned int w, unsigned int h)
{
	gridWidth = w;
	gridHeight = h;
	init_textures();
	populate_grid();
}

sf::Vector2i grid::get_grid_size()
{
	return sf::Vector2i(gridWidth, gridHeight);
}

int grid::row_count()
{
	return gridHeight / cellSize;
}

int grid::col_count()
{
	return gridWidth / cellSize;
}

void grid::update(sf::RenderWindow& window)
{
	update_grid(window);
	update_mouse(window);
}

void grid::populate_grid()
{
	play_area.clear();

	int rows = row_count();
	int cols = col_count();

	for (int y = 0; y < rows; ++y) {
		std::vector<grid_space> row;
		for (int x = 0; x < cols; ++x) {
			grid_space space(shared_from_this(), x * cellSize, y * cellSize, cellSize, 
				cellSize, grid_space_texture);
			row.emplace_back(space);
		}
		play_area.push_back(row);
	}
}

void grid::init_textures()
{
	string gridSpaceTexture = "Assets/grid_texture.png";
	string mouseTexture = "Assets/mouse_texture.png";
	std::filesystem::path gridSpaceAb = std::filesystem::absolute(gridSpaceTexture);
	std::filesystem::path mouseAb = std::filesystem::absolute(mouseTexture);

	try {
		if (!grid_space_texture.loadFromFile(gridSpaceAb.string())) {
			throw std::runtime_error("Failed to load texture from " + gridSpaceAb.string());
		}
		if (!mouse_texture.loadFromFile(mouseAb.string())) {
			throw std::runtime_error("Failed to load texture from " + mouseAb.string());
		}
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "Texture loaded successfully." << std::endl;
}

void grid::spawn_mouse(sf::Vector2i pos, sf::RenderWindow& window)
{
	if (!mouse) {
		mouse = std::make_shared<sf::Sprite>(sf::Sprite());
		if (mouse) {
			mouse->setTexture(mouse_texture);
			mouse->setPosition(
				static_cast<float>(pos.x * cellSize), 
				static_cast<float>(pos.y * cellSize));
		}
	}
}

sf::Vector2i grid::get_random_grid_pos()
{
	int min = 0;
	int xMax = col_count() - 1;
	int yMax = row_count() - 1;

	static std::random_device seed;
	static std::mt19937 gen(seed());

	std::uniform_int_distribution<int> xDist(min, xMax);
	std::uniform_int_distribution<int> yDist(min, yMax);

	return sf::Vector2i(xDist(gen), yDist(gen));
}

void grid::update_grid(sf::RenderWindow& window)
{
	int rows = row_count();
	int cols = col_count();
	// Loop over all spaces and draw.
	for (int y = 0; y < rows; ++y) {
		for (int x = 0; x < cols; ++x) {
			grid_space& space = play_area[x][y];
			window.draw(space.get_sprite());
		}
	}
}

void grid::update_mouse(sf::RenderWindow& window)
{
	// If there is no mouse, create a new one.
	if (!mouse) {
		sf::Vector2i mousePos = get_random_grid_pos();
		// TODO: loop through all snake segments and choose a different location if 
		// the mouse spawn location is on the snakes body. 
		spawn_mouse(mousePos, window);
	}
	else {
		if (!gameInst) return;

		// If mouse and snake intersect, increase score, set mouse to null.
		shared_ptr<snake_character> snakeChar = gameInst->get_snake_character();
		if (mouse->getGlobalBounds().intersects(
			snakeChar->get_sprite().getGlobalBounds())) {
			gameInst->increase_score(1);
			mouse = nullptr;
		}
		else
		{
			window.draw(*mouse);
		}

	}
}
