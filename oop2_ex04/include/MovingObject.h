#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
//#include "Board.h"
#include "FileManager.h"
#include <deque>  
#include <queue> 
#include <limits.h>
#include <stdio.h>

using namespace std;
using std::vector;



class MovingObject
{
public:
	virtual MovingObject()=0;
	~MovingObject() {};

	bool reachedTheExit() { return m_reachedTheExit; }
	bool trapped() { return m_trapped; }
	void resetReachedTheExit() { m_reachedTheExit = false; };
	void resetTrapped() { m_trapped = false; };

	//void move(std::vector<std::vector<sf::CircleShape>>, sf::Time& deltaTime);
	sf::Vector2i getNextMove(std::vector<std::vector<sf::CircleShape>>, sf::Vector2i);
	void setPos(sf::Vector2f pos) { m_sprite.setPosition(pos); }
	sf::Vector2f getPos() { return m_sprite.getPosition(); };
	void resetMatrix(std::vector<std::vector<sf::Vector2<int>>>&);
	sf::Vector2<int> calaulateFirstMove(std::vector<std::vector<sf::Vector2<int>>>,
		sf::Vector2<int>, sf::Vector2<int>);
	bool canMove(std::vector<std::vector<sf::CircleShape>>, sf::Vector2i);

private:
	void updateAnimation();
	bool isLineEven(int);
	sf::Vector2<int> grillDirection(bool) const;
	bool winSituation(sf::Vector2i);
	bool isValid(int);
	sf::Vector2i moveObjectRandomly(std::vector<std::vector<sf::CircleShape>>, sf::Vector2i);
	void fillVisitedAndFindSource(std::vector<std::vector<sf::CircleShape>>, sf::Vector2i&,
		bool[BOARD_LEN][BOARD_LEN]);
	void checkDirection(int x, int y, bool visited[BOARD_LEN][BOARD_LEN],
		std::queue<sf::Vector2i >& q,
		std::vector<std::vector<sf::Vector2i>>& , sf::Vector2i );

	sf::Sprite m_sprite;
	bool m_reachedTheExit = false;
	bool m_trapped = false;
	sf::Vector2f m_currDirection;
};
