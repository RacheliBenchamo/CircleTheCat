#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
#include<stdio.h>
#include <fstream>
#include <iostream>

#include "macros.h"

using std::fstream;
//using std::cerr;
const unsigned int P_SIZE = 75; // pixel size
class Board
{
public:
	Board();
	~Board() {};

	//void drawIcons(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window)const;

	void mouseMoved(sf::Event event, sf::RenderWindow& window);
	void mouseButtonReleased(sf::Event event, sf::RenderWindow& window);
	bool inWindow(sf::Event event);

private:
	void setBoard();
	void setTitle();
	void setGrid();
	void drawGrid(sf::RenderWindow& window)const;

	int m_clickCount = 0;
	sf::Texture m_title;
	sf::Sprite m_spriteTitle;
	std::vector<std::vector<sf::Vector2f>> m_levels;
	std::vector<std::vector<sf::CircleShape>> m_board;
	sf::CircleShape m_movingCircle;
	
};

