#include "UI.h"
#include "../framework/game.h"
#include "../gameobjects/grid.h"
#include <filesystem>
#include <iostream>
#include <string>

ui::ui(shared_ptr<class game> gInst)
	:gameInst(gInst)
{

}

void ui::load_font()
{
	std::string path = "Assets/Pixeled.ttf";
	std::filesystem::path absPath = std::filesystem::absolute(path);

	if (!font.loadFromFile(absPath.string())) {
		try {
			throw std::runtime_error("Failed to load texture from " + absPath.string());
		}
		catch (std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
		return;
	}

	std::cout << "Fonts loaded successfully!";
}

sf::Text ui::get_score_text()
{
	update_score();
	return scoreText;
}

void ui::update_score()
{
	if (!gameInst) return;

	std::string scoreString = std::to_string(gameInst->get_score());
	scoreText.setString(scoreString);
	scoreText.setFont(font);
	scoreText.setCharacterSize(50);
	//scoreText.setColor(sf::Color::White);

	shared_ptr<grid> gameGrid = gameInst->get_grid();
	if (!gameGrid) return;

	sf::Vector2f pos(
		static_cast<float>(gameGrid->get_grid_size().x) + 5.0f,
		10.0f // Adjust Y position to avoid overlap
	);
	scoreText.setPosition(pos);
}
