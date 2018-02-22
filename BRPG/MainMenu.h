#pragma once

#include "Game.h"
#include "State.h"

extern bool quitGame;
extern Game game;

class MainMenu : public State
{
	public:
		void Initialize(sf::RenderWindow* window);
		void Update(sf::RenderWindow* window);
		void Render(sf::RenderWindow* window);
		void Destroy(sf::RenderWindow* window);
		void Event(sf::RenderWindow* window, sf::Event* event);

	private:
		sf::Font* font;
		sf::Text* title;
		sf::Text* play;
		sf::Text* settings;
		sf::Text* quit;

		int selected;
		bool up, down;
};