#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Game.h"
#include "MainMenu.h"
#include "Settings.h"

const double frame = 0.045f;

Game game;
bool quitGame = false;

int main()
{
	sf::VideoMode videoMode(game.getSetting("Width"), game.getSetting("Height"), 32U);

	sf::RenderWindow window(videoMode, "BRPG", sf::Style::None);

	sf::Clock clock;

	game.setWindow(&window);
	game.setState(new MainMenu());

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			game.Event(&window, &event);
		}
		
		window.clear(sf::Color::White);

		while (clock.getElapsedTime().asSeconds() < frame);
		clock.restart();

		game.Update();
		game.Render();

		window.display();

		if (quitGame)
			window.close();
	}

	return EXIT_SUCCESS;
}