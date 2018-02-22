#pragma once

#include "Game.h"
#include "MainMenu.h"
#include "Settings.h"

extern bool quitGame;
extern Game game;

class SetSettings : public State
{
	public:
		void Initialize(sf::RenderWindow* window);
		void Update(sf::RenderWindow* window);
		void Render(sf::RenderWindow* window);
		void Destroy(sf::RenderWindow* window);
		void Event(sf::RenderWindow* window, sf::Event* event);

	private:
		sf::Font* font;
		sf::Text* settings;
		sf::Text* resolution;
		Settings objSettings;

		int selected;
		bool up, down;
};