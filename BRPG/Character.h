#pragma once

#include <SFML/Graphics.hpp>

class Character : public sf::Drawable, public sf::Transformable
{
	public:
		enum Direction { Down, Left, Right, Up };
		Character(std::string spritesheet, sf::Vector2f position);
		void Update(sf::RenderWindow* window);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		sf::Texture texture;
		sf::Sprite sprite;

		Character::Direction direction;

		int animationState;
};