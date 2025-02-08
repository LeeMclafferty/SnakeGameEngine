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

void ui::update(sf::RenderWindow& window)
{
	window.draw(get_score_text());
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

void ui::game_over(sf::RenderWindow& window)
{
	gameOverText.setString("Game Over");
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(20);
	
	restartText.setString("Press space to play again");
	restartText.setFont(font);
	restartText.setCharacterSize(10);

	// Calculate text position.
	float centerX = static_cast<float>(window.getSize().x / 3);
	float centerY = static_cast<float>(window.getSize().y / 3);

	gameOverText.setPosition(sf::Vector2f(centerX, centerY));
	restartText.setPosition(centerX - 30, centerY + 30);

	window.draw(gameOverText);
	window.draw(restartText);

	scoreText.setPosition(centerX, centerY + 5);
	window.draw(scoreText);
}

void ui::update_score()
{
	if (!gameInst) return;

	std::string scoreString = "\n Score: " + std::to_string(gameInst->get_score());
	scoreText.setString(scoreString);
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	//scoreText.setColor(sf::Color::White);

	shared_ptr<grid> gameGrid = gameInst->get_grid();
	if (!gameGrid) return;

	sf::Vector2f pos(
		static_cast<float>(gameGrid->get_grid_size().x) + 5.0f,
		10.0f // Adjust Y position to avoid overlap
	);
	scoreText.setPosition(pos);
}
