#pragma once
//#include <SFML\Graphics.hpp>
//#include <vector>
#include <memory>
#include<stdio.h>
#include <fstream>
#include <iostream>
#include "macros.h"
#include "cat.h"


using std::fstream;
class Board
{
public:
	Board();
	~Board() {};

	void draw(sf::RenderWindow& window)const;
	void mouseButtonReleased(sf::Event event, sf::RenderWindow& window);
	void setClickCount(const int clicks) { m_clickCount = clicks; }
	int getClickCount()const { return m_clickCount; }
	void setWinLevel(const bool isWin) { m_winLevel = isWin; }
	bool getWinLevel() const { return m_winLevel; }
	void setLoseLevel(const bool isWin) { m_loseLevel = isWin; }
	bool getLoseLevel() const { return m_loseLevel; }
	void restartLevel();
	void startNewLevel();
	void undo();

private:
	void setBoard();
	void setGrid();
	void setLevel();
	void setCat();
	void SelectRandomColoredCircles();
	void UpdatePaintedCircles();
	void ColoringCirclesToBeginningColor();
	void unColoringCurrentCircle(int, int);
	void coloringCurrentCircle(int, int);
	void drawGrid(sf::RenderWindow& window)const;
	void takeCatBackToPrevPos();

	int m_maxColoredCircles = 14;
	bool m_winLevel = false;
	bool m_loseLevel = false;
	bool m_restart = false;
	int m_clickCount = 0;
	Cat m_cat;
	std::vector<std::vector<sf::CircleShape>> m_grid;
	std::vector<sf::Vector2f> m_randomColoredCircles;	
	std::vector<sf::Vector2f> m_clikedCircles;
	std::vector<sf::Vector2f> m_catWay;


};

