#include "MainMenu.h"
#include "SetSettings.h"
#include "MainGame.h"

void MainMenu::Initialize(sf::RenderWindow* window)
{
	this->selected = 0;

	this->font = new sf::Font();
	this->font->loadFromFile("font.ttf");

	this->title = new sf::Text("BRPG", *this->font, window->getSize().x / 15);
	this->play = new sf::Text("New Game", *this->font, window->getSize().x / 30);
	this->settings = new sf::Text("Settings", *this->font, window->getSize().x / 30);
	this->quit = new sf::Text("Quit", *this->font, window->getSize().x / 30);

	this->title->setColor(sf::Color::Black);
}

void MainMenu::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !this->up)
		selected--;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !this->down)
		selected++;

	if (selected > 2)
		selected = 0;

	if (selected < 0)
		selected = 2;

	up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

	if (this->play->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		this->selected = 0;

	if (this->settings->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		this->selected = 1;

	if (this->quit->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		this->selected = 2;
}

void MainMenu::Render(sf::RenderWindow* window)
{
	this->play->setColor(sf::Color(128, 128, 128, 64U));
	this->settings->setColor(sf::Color(128, 128, 128, 64U));
	this->quit->setColor(sf::Color(128, 128, 128, 64U));

	switch (selected)
	{
		case 0:
			this->play->setColor(sf::Color(256, 256, 256, 128U));
			break;

		case 1:
			this->settings->setColor(sf::Color(256, 256, 256, 128U));
			break;

		case 2:
			this->quit->setColor(sf::Color(256, 256, 256, 128U));
			break;
	}

	this->title->setOrigin(sf::Vector2f(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2));
	this->title->setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 4));

	this->play->setOrigin(sf::Vector2f(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2));
	this->play->setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 12 * 6));

	this->settings->setOrigin(sf::Vector2f(this->settings->getGlobalBounds().width / 2, this->settings->getGlobalBounds().height / 2));
	this->settings->setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 12 * 7));

	this->quit->setOrigin(sf::Vector2f(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2));
	this->quit->setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 12 * 8));

	window->draw(*this->title);
	window->draw(*this->play);
	window->draw(*this->settings);
	window->draw(*this->quit);
}

void MainMenu::Destroy(sf::RenderWindow* window)
{
	delete this->font;
	delete this->title;
	delete this->settings;
	delete this->play;
	delete this->quit;
}

void MainMenu::Event(sf::RenderWindow* window, sf::Event* event)
{
	if ((event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Return) || (event->type == sf::Event::MouseButtonPressed && event->mouseButton.button == sf::Mouse::Left))
	{
		switch (this->selected)
		{
			case 0:
				game.setState(new MainGame());
				break;

			case 1:
				game.setState(new SetSettings());
				break;

			case 2:
				quitGame = true;
				break;
		}
	}
}
