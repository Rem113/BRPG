#pragma once

#include <SFML/Graphics.hpp>

class Camera
{
	public:
		void Initialize(sf::RenderWindow* window, sf::Vector2f position);
		void Update(sf::RenderWindow* window, sf::Vector2f position);

	private:
		sf::View view;
};