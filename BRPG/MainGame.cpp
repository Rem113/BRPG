#include "MainGame.h"
#include "MainMenu.h"

void MainGame::Initialize(sf::RenderWindow* window)
{
	this->map = new Map;
	this->map->Initialize("spritesheet.png", window);
	this->map->LoadMap("level_1.data", "floor_tileset.png", window);
}

void MainGame::Update(sf::RenderWindow* window)
{
	this->map->Update(window);
}

void MainGame::Render(sf::RenderWindow* window)
{
	this->map->Render(window);
}

void MainGame::Destroy(sf::RenderWindow* window)
{
	window->setView(window->getDefaultView());
	this->map->Destroy();
	delete this->map;
}

void MainGame::Event(sf::RenderWindow* window, sf::Event* event)
{
	if (event->type == sf::Event::KeyPressed)
	{
		switch (event->key.code)
		{
			case sf::Keyboard::Escape:
				game.setState(new MainMenu());
			break;
		}
	}
}