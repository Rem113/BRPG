#include "SetSettings.h"
#include <vector>

void SetSettings::Initialize(sf::RenderWindow* window)
{
	this->selected = 0;

	this->font = new sf::Font();
	this->font->loadFromFile("font.ttf");

	this->settings = new sf::Text("Settings", *this->font, window->getSize().x / 15);
	this->resolution = new sf::Text("Resolution : ", *this->font, window->getSize().x / 30);

	this->settings->setColor(sf::Color::Black);

	this->objSettings.setSettingsArray(game.getSettingsArray());
}

void SetSettings::Update(sf::RenderWindow* window)
{
	this->resolution->setString("Resolution : " + std::to_string(this->objSettings.getSetting("Width")) + " x " + std::to_string(this->objSettings.getSetting("Height")));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !this->up)
		selected--;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !this->down)
		selected++;

	if (selected > 0)
		selected = 0;

	if (selected < 0)
		selected = 0;

	up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

	if (this->resolution->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		this->selected = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		game.setState(new MainMenu());
}

void SetSettings::Render(sf::RenderWindow* window)
{
	this->resolution->setColor(sf::Color(128, 128, 128, 64U));

	switch (selected)
	{
		case 0:
			this->resolution->setColor(sf::Color(256, 256, 256, 128U));
			break;
	}

	this->settings->setOrigin(sf::Vector2f(this->settings->getGlobalBounds().width / 2, this->settings->getGlobalBounds().height / 2));
	this->settings->setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 4));

	this->resolution->setOrigin(sf::Vector2f(this->resolution->getGlobalBounds().width / 2, this->resolution->getGlobalBounds().height / 2));
	this->resolution->setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 4));

	window->draw(*this->settings);
	window->draw(*this->resolution);
}

void SetSettings::Destroy(sf::RenderWindow* window)
{
	game.setSettingsArray(this->objSettings.getSettingsArray());
	game.UpdateSettings();

	delete this->font;
	delete this->settings;
	delete this->resolution;
}

void SetSettings::Event(sf::RenderWindow* window, sf::Event* event)
{
	if ((event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Return) || (event->type == sf::Event::MouseButtonPressed && event->mouseButton.button == sf::Mouse::Left))
	{
		switch (this->selected)
		{
			case 0:
				std::vector<sf::VideoMode> videoModes = sf::VideoMode::getFullscreenModes();

				bool changed = false;

				for (int i = videoModes.size() - 1; i != -1; i--)
				{
					if (this->objSettings.getSetting("Width") == videoModes[i].width && this->objSettings.getSetting("Height") == videoModes[i].height)
					{
						if (i == 0 && !changed)
						{
							this->objSettings.setSetting("Width", videoModes[videoModes.size() - 1].width);
							this->objSettings.setSetting("Height", videoModes[videoModes.size() - 1].height);
							changed = true;
						}

						else if (!changed)
						{
							this->objSettings.setSetting("Width", videoModes[i - 1].width);
							this->objSettings.setSetting("Height", videoModes[i - 1].height);
							changed = true;
						}

						this->resolution->setString("Resolution : " + std::to_string(this->objSettings.getSetting("Width")) + " x " + std::to_string(this->objSettings.getSetting("Height")));
					}
				}

			break;
		}
	}
}
