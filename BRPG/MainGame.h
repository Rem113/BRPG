#pragma once

#include "Game.h"
#include "Map.h"
#include "Character.h"

extern bool quitGame;
extern Game game;

class MainGame : public State
{
	public:
		void Initialize(sf::RenderWindow* window);
		void Update(sf::RenderWindow* window);
		void Render(sf::RenderWindow* window);
		void Destroy(sf::RenderWindow* window);
		void Event(sf::RenderWindow* window, sf::Event* event);

	private:
		Map* map;
};