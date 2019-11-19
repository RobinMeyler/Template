#include "Game.h"


Game::Game() :
	m_window{ sf::VideoMode{ 2000, 2000, 32 }, "Controller Class" },
	m_exitGame{ false }

{
	// create
	int index = 0;
	
	f.loadFromFile("digital-7.ttf");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			t[i][j].index = index;
			t[i][j].m_pos = sf::Vector2f(j * 100, i * 100);
			t[i][j].m_box.setFillColor(sf::Color::White);
			t[i][j].m_box.setOutlineColor(sf::Color::Black);
			t[i][j].m_box.setOutlineThickness(2);
			t[i][j].m_box.setSize(sf::Vector2f(100, 100));
			t[i][j].m_box.setPosition(t[i][j].m_pos);

			t[i][j].m_text.setString(std::to_string(index));
			t[i][j].m_text.setFillColor(sf::Color::Blue);
			t[i][j].m_text.setFont(f);
			t[i][j].m_text.setCharacterSize(30);
			t[i][j].m_text.setPosition(t[i][j].m_pos);
		    index++;
		}
	}

	t[4][5].isWall = true;
	t[4][5].m_box.setFillColor(sf::Color::Black);
	t[5][5].isWall = true;
	t[5][5].m_box.setFillColor(sf::Color::Black);
	// the Boys
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			
				if (i < 9)
				{
					t[i][j].m_neighbours.push_back(&t[i + 1][j]);
				}
				if (j > 0)
				{
					t[i][j].m_neighbours.push_back(&t[i][j - 1]);
				}
				if (j < 9)
				{
					t[i][j].m_neighbours.push_back(&t[i][j + 1]);
				}
				if (i > 0)
				{
					t[i][j].m_neighbours.push_back(&t[i - 1][j]);
				}
			
		}
	}

}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::processEvents()
{
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				click = true;
				m_mousePosition = sf::Mouse::getPosition(m_window);
			}
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				
			}
		}
	}
}

void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();		// Exiting the game
	}
	if (click == true)
	{
		sf::Vector2i oop;
		oop.x = m_mousePosition.x / 100;
		oop.x = oop.x * 100;

		oop.y = m_mousePosition.y / 100;
		oop.y = oop.y * 100;
		
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if ((sf::Vector2i)t[i][j].m_pos == oop)
				{
					t[i][j].getNeigh(0.1);
				}
			}

		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				t[i][j].update(t_deltaTime);
			}
		}
	}
}

void Game::render()
{
	m_window.clear(sf::Color::Black);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			m_window.draw(t[i][j].m_box);
			m_window.draw(t[i][j].m_text);
		}
	}


	m_window.display();
}

