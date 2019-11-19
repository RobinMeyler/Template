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
	bool isWall{ false };
	void getNeigh(float time);
	void setTimer(float time);
	void update(sf::Time del);

private:
	float timer{ 0 };
	bool light{ false };

};

