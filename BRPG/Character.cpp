#include "Character.h"
#include <iostream>

Character::Character(std::string spritesheet, sf::Vector2f position)
{
	this->texture.loadFromFile(spritesheet);
	this->animationState = 0;
	this->direction = Character::Direction::Down;
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(sf::IntRect(this->animationState * 32, this->direction * 48, 32, 48));
	this->setPosition(position);
	this->sprite.setPosition(position);
}

void Character::Update(sf::RenderWindow* window)
{
	this->sprite.setTextureRect(sf::IntRect(this->animationState * 32, this->direction * 48, 32, 48));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->direction = Character::Direction::Down;

		this->move(0.0f, 4.0f);

		++this->animationState;

		if (this->animationState > 2)
			this->animationState = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->direction = Character::Direction::Up;

		this->move(0.0f, -4.0f);

		++this->animationState;

		if (this->animationState > 2)
			this->animationState = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->direction = Character::Direction::Left;

		this->move(-4.0f, 0.0f);

		++this->animationState;

		if (this->animationState > 2)
			this->animationState = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->direction = Character::Direction::Right;

		this->move(4.0f, 0.0f);

		++this->animationState;

		if (this->animationState > 2)
			this->animationState = 0;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->animationState = 0;
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(this->sprite, states);
}
