#include "Camera.h"

void Camera::Initialize(sf::RenderWindow* window, sf::Vector2f position)
{
	this->view = window->getDefaultView();
	this->view.setCenter(position);
	window->setView(this->view);
}

void Camera::Update(sf::RenderWindow* window, sf::Vector2f position)
{
	this->view.setCenter(position);
	window->setView(this->view);
}
