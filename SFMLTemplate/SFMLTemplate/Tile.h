#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Tile
{
public:
	Tile();
	~Tile();

	sf::Vector2f m_pos;
	int index;
	int found{ false };
	std::vector<Tile*> m_neighbours;
	sf::RectangleShape m_box;
	sf::Text m_text;

	void getNeigh();


private:



};

