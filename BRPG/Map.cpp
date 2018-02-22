#include "Map.h"
#include <fstream>
#include <sstream>
#include <cctype>

void Map::Initialize(std::string spritesheet, sf::RenderWindow* window)
{
	this->character = new Character(spritesheet, sf::Vector2f(this->width / 2, this->height / 2));
	this->camera = new Camera;
	this->camera->Initialize(window, this->character->getPosition());
}

void Map::Update(sf::RenderWindow* window)
{
	this->camera->Update(window, this->character->getPosition());
	this->character->Update(window);
}

void Map::Render(sf::RenderWindow* window)
{
	window->draw(*this);
	window->draw(*this->character);
}

void Map::Destroy()
{
	delete this->character;
	delete this->camera;
}

void Map::LoadMap(std::string map, std::string tileset, sf::RenderWindow* window)
{
	this->map.clear();

	this->tileset.loadFromFile(tileset);

	std::ifstream reader(map);
	std::vector<sf::Vector2i> tempMap;
	std::string str, value;

	while (!reader.eof())
	{
		std::getline(reader, str);
		std::stringstream stream(str);

		while (std::getline(stream, value, ' '))
		{
			if (value.length() > 0)
			{
				std::string xx, yy;
				xx = value.substr(0, value.find(','));
				yy = value.substr(value.find(',') + 1);

				unsigned int x, y, i, j;

				for (i = 0; i < xx.length(); i++)
				{
					if (!isdigit(xx[i]))
						break;
				}

				for (j = 0; j < yy.length(); j++)
				{
					if (!isdigit(yy[j]))
						break;
				}

				x = (i == xx.length()) ? atoi(xx.c_str()) : -1;
				y = (j == yy.length()) ? atoi(yy.c_str()) : -1;

				tempMap.push_back(sf::Vector2i(x, y));
			}
		}

		this->map.push_back(tempMap);
		tempMap.clear();
	}

	reader.clear();

	this->width = this->map[0].size() * 32;
	this->height = this->map.size() * 32;

	std::vector<sf::VertexArray> temp;

	for (int i = 0; i < this->map[0].size(); ++i)
	{
		for (int j = 0; j < this->map.size(); ++j)
			temp.push_back(sf::VertexArray(sf::PrimitiveType::Quads, 4));

		this->mapRender.push_back(temp);
		temp.clear();
	}

	for (unsigned int i = 0; i < this->map[0].size(); ++i)
	{
		for (unsigned int j = 0; j < this->map.size(); ++j)
		{
			if (this->map[j][i].x != -1 && this->map[j][i].y != -1)
			{
				this->mapRender[i][j][0].position = sf::Vector2f(i * 32, j * 32);
				this->mapRender[i][j][1].position = sf::Vector2f(i * 32 + 32, j * 32);
				this->mapRender[i][j][2].position = sf::Vector2f(i * 32 + 32, j * 32 + 32);
				this->mapRender[i][j][3].position = sf::Vector2f(i * 32, j * 32 + 32);

				this->mapRender[i][j][0].texCoords = sf::Vector2f(this->map[j][i].x * 32, this->map[j][i].y * 32);
				this->mapRender[i][j][1].texCoords = sf::Vector2f(this->map[j][i].x * 32 * 32 + 32, this->map[j][i].y * 32);
				this->mapRender[i][j][2].texCoords = sf::Vector2f(this->map[j][i].x * 32 + 32, this->map[j][i].y * 32 + 32);
				this->mapRender[i][j][3].texCoords = sf::Vector2f(this->map[j][i].x * 32, this->map[j][i].y * 32 + 32);
			}
		}
	}
}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &this->tileset;

	for (int i = 0; i < this->width / 32; ++i)
	{
		for (int j = 0; j < this->height / 32; ++j)
			target.draw(this->mapRender[i][j], states);
	}
}
