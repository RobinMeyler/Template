#ifndef GAME
#define GAME


#include <SFML\Graphics.hpp>
#include"Xbox360Controller.h"
#include "Tile.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();				// Loop functions
	void update(sf::Time t_deltaTime);
	void render();
	sf::Event event;
	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	bool m_exitGame; // control exiting game
	Tile t[10][10];
	sf::Font f;
	sf::Vector2i m_mousePosition; // = sf::Mouse::getPosition(m_renderWin);
	bool click{ false };
	int size{ 10 };
};

#endif // !GAME

