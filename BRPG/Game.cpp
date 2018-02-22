#include "Game.h"

Game::Game()
{
	this->state = NULL;
}

int Game::getSetting(std::string name)
{
	return this->settings.getSetting(name);
}

void Game::setSetting(std::string name, int value)
{
	this->settings.setSetting(name, value);
}

std::map<std::string, int> Game::getSettingsArray()
{
	return this->settings.getSettingsArray();
}

void Game::setSettingsArray(std::map<std::string, int> settingsArray)
{
	this->settings.setSettingsArray(settingsArray);
}

void Game::setWindow(sf::RenderWindow* window)
{
	this->window = window;
}

void Game::setState(State* state)
{
	if (this->state != NULL)
		this->state->Destroy(this->window);

	this->state = state;

	if (this->state != NULL)
		this->state->Initialize(this->window);
}

void Game::Update()
{
	if (this->state != NULL)
		this->state->Update(this->window);
}

void Game::Render()
{
	if (this->state != NULL)
		this->state->Render(this->window);
}

void Game::Event(sf::RenderWindow* window, sf::Event* event)
{
	this->state->Event(window, event);
}

void Game::UpdateSettings()
{
	this->window->setSize(sf::Vector2u(this->settings.getSetting("Width"), this->settings.getSetting("Height")));
}

Game::~Game()
{
	if (this->state != NULL)
		this->state->Destroy(this->window);

	delete this->state;
}
