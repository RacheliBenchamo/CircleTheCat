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

	void drawIcons(sf::RenderWindow& window);
	void drawGrid(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

	void mouseMoved(sf::Event event, sf::RenderWindow& window);
	void mouseButtonReleased(sf::Event event, sf::RenderWindow& window);

	bool getClear() { return m_clear; }
	bool getExistFile() { return m_existFile; }
	sf::Vector2f getBoardSize() { return m_boardSize; }

	bool inWindow(sf::Event event);

private:
	void setBoard();
	void setToolbarRect(sf::RectangleShape& rect, sf::Vector2f pos);
	void saveInFile();
	void readData();
	void readChar(const char c, size_t i, size_t j);
	void readFromUser();
	void writeInput(std::ofstream& output, Toolbar_t shape);

	bool m_clear = false;
	bool m_existFile;
	bool m_eraseMode = true;
	Toolbar m_toolbar;
	vector<vector<std::unique_ptr<Icon>>>m_grid;
	Toolbar_t m_newIcon;

	bool m_haveKing = true;
	bool m_haveThief = true;
	bool m_haveWarrior = true;
	bool m_haveMage = true;
	bool m_haveThrone = true;
	sf::Vector2f m_kingPos;
	sf::Vector2f m_thiefPos;
	sf::Vector2f m_warriorPos;
	sf::Vector2f m_magePos;
	sf::Vector2f m_boardSize;
	sf::RectangleShape m_currSprite;
	sf::RectangleShape m_movingRec;
	sf::Sprite m_movingIcon;
};

