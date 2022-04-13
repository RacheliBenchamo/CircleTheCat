#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <memory>
#include<stdio.h>
#include <fstream>


using std::fstream;
//using std::cerr;
const unsigned int P_SIZE = 60; // pixel size
class Board
{
public:
	Board();
	~Board() {};

	//void drawIcons(sf::RenderWindow& window);
	void drawGrid(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

	void mouseMoved(sf::Event event, sf::RenderWindow& window);
	void mouseButtonReleased(sf::Event event, sf::RenderWindow& window);

	bool getClear() { return m_clear; }
	sf::Vector2f getBoardSize() { return m_boardSize; }

	bool inWindow(sf::Event event);

private:
	void setBoard();
	

	bool m_clear = false;
	//vector<vector<std::unique_ptr<Icon>>>m_grid;

	sf::Vector2f m_boardSize;
	sf::RectangleShape m_currSprite;
	sf::RectangleShape m_movingRec;
	sf::Sprite m_movingIcon;
};

