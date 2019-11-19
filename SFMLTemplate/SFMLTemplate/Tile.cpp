#include "Tile.h"

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::getNeigh()
{
	found = true;
	for (int i = 0; i < m_neighbours.size(); i++)
	{
		if (m_neighbours.at(i)->found == false)
		{
			m_box.setFillColor(sf::Color::Red);
			std::cout << index << std::endl;
			m_neighbours.at(i)->getNeigh();
			//m_neighbours.at(i)->found = false;
		}

	}

}
