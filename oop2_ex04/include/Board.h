#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
#include<stdio.h>
#include <fstream>
#include <iostream>
#include "macros.h"

using std::fstream;
class Board
{
public:
	Board();
	~Board() {};

	void draw(sf::RenderWindow& window)const;
	void mouseMoved(sf::Event event, sf::RenderWindow& window);
	void mouseButtonReleased(sf::Event event, sf::RenderWindow& window);
	bool inWindow (sf::Event event)const;
	void setClickCount(const int clicks) { m_clickCount = clicks; }
	int getClickCount()const { return m_clickCount; }
	void setWinLevel(const bool isWin) { m_winLevel = isWin; }
	bool getWinLevel() const { return m_winLevel; }

private:
	void setBoard();
	void setGrid();
	void drawGrid(sf::RenderWindow& window)const;

	bool m_winLevel = false;
	int m_clickCount = 0;
	std::vector<std::vector<sf::Vector2f>> m_levels;
	std::vector<std::vector<sf::CircleShape>> m_board;
	//sf::CircleShape m_movingCircle;
	
};

