#pragma once
#include "Game.h"
#include "MainMenu.h"

int play(sf::RenderWindow& window) {	
	sf::Font font;
	font.loadFromFile(FONT_FILEPATH);

	sf::Text text("Arrow keys - move, Tab - New game, Esc - Back to menu", font, 25);
	
	text.setFillColor(sf::Color::White);
	text.setPosition(10.f, 10.f);


	Game game;
	game.setPosition(50.f, 50.f);

	sf::Event event;
	int count = 0;	

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed)
			{

				if (event.key.code == sf::Keyboard::Escape) return 0;
				if (event.key.code == sf::Keyboard::Up) game.Move(Direction::Up);
				if (event.key.code == sf::Keyboard::Down) game.Move(Direction::Down);
				if (event.key.code == sf::Keyboard::Left) game.Move(Direction::Left);
				if (event.key.code == sf::Keyboard::Right) game.Move(Direction::Right);
				if (event.key.code == sf::Keyboard::Tab)
				{
					game.Init();
					count = 150;
				}
			}
		}

		while (count > 0) {
			game.Move((Direction)(rand() % 4));
			count--;}
		window.clear();
		window.draw(text);
		window.draw(game);
		window.display();
	}
	}

int main()
{
	sf::RenderWindow window(sf::VideoMode(GAME_SIZE, GAME_SIZE), "15 Puzzle");
	window.setFramerateLimit(50);
	auto menu = MainMenu(window);
	menu.init();

	while (window.isOpen()){
		menu.draw();
		if (menu.handleInput() == 1){
			play(window);
		}
	}
}