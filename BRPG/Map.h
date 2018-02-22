#pragma once

#include <SFML\Graphics.hpp>
#include <string>
#include <vector>

#include "Character.h"
#include "Camera.h"

class Map : public sf::Drawable, public sf::Transformable
{
	public:
		void LoadMap(std::string map, std::string tileset, sf::RenderWindow* window);
		void Initialize(std::string spritesheet, sf::RenderWindow* window);
		void Update(sf::RenderWindow* window);
		void Render(sf::RenderWindow* window);
		void Destroy();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		sf::Texture tileset;

		Character* character;
		Camera* camera;

		std::vector<std::vector<sf::Vector2i>> map;
		std::vector<std::vector<sf::VertexArray>> mapRender;

		int width, height;
};