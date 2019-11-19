#include "Tile.h"

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::getNeigh(float time)
{
	
	float tume = time + 0.1;
	for (int i = 0; i < m_neighbours.size(); i++)
	{
		if (m_neighbours.at(i)->found == false && m_neighbours.at(i)->isWall == false)
		{
			m_neighbours.at(i)->found = true;
			m_neighbours.at(i)->setTimer(tume);
			std::cout << index << std::endl;
			m_neighbours.at(i)->getNeigh(tume);
			//m_neighbours.at(i)->found = false;
		}
	}
}

void Tile::setTimer(float time)
{
	timer = time;
}

void Tile::update(sf::Time del)
{
	if (timer > 0)
	{
		light = true;
		timer -= del.asSeconds();
	}
	else
	{
		if (light == true)
		{
			m_box.setFillColor(sf::Color::Red);
		}
	}

}
