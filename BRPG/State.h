#pragma once

#include <SFML\Graphics.hpp>

class State
{
	public:
		virtual void Initialize(sf::RenderWindow* window) = 0;
		virtual void Update(sf::RenderWindow* window) = 0;
		virtual void Render(sf::RenderWindow* window) = 0;
		virtual void Destroy(sf::RenderWindow* window) = 0;
		virtual void Event(sf::RenderWindow* window, sf::Event* event) = 0;
};