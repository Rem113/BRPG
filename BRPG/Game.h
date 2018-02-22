#pragma once

#include <SFML\Graphics.hpp>
#include "State.h"
#include "Settings.h"

extern bool quitGame;

class Game
{
	public:
		Game();
		int getSetting(std::string name);
		void setSetting(std::string name, int value);
		std::map<std::string, int> getSettingsArray();
		void setSettingsArray(std::map<std::string, int> settingsArray);
		void setWindow(sf::RenderWindow* window);
		void setState(State* state);
		void Update();
		void Render();
		void Event(sf::RenderWindow* window, sf::Event* event);
		void UpdateSettings();
		~Game();

	private:
		sf::RenderWindow* window;
		State* state;
		Settings settings;
};