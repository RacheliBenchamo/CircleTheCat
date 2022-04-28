#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
//#include "Board.h"
#include "FileManager.h"
using std::vector;



class Cat
{
public:
	Cat();
	~Cat() {};

	bool reachedTheExit() { return m_reachedTheExit; }
	bool trapped() { return m_trapped; }
	void resetReachedTheExit() { m_reachedTheExit = false; };
	void resetTrapped() { m_trapped = false; };

	void move(std::vector<std::vector<sf::CircleShape>>) ;
	void draw (sf::RenderWindow& window) const {window.draw(m_sprite);}
	sf::Vector2<int> findAPath(std::vector<std::vector<sf::CircleShape>> );
	void setPos(sf::Vector2f pos) { m_sprite.setPosition(pos); };
	sf::Vector2f getPos() { return m_sprite.getPosition(); };
	void resetMatrix(std::vector<std::vector<sf::Vector2<int>>> &);
	sf::Vector2<int> calaulateFirstMove(std::vector<std::vector<sf::Vector2<int>>>, 
		sf::Vector2<int>, sf::Vector2<int>);
	bool canMove(std::vector<std::vector<sf::CircleShape>> , sf::Vector2<int> );

private:
	bool isLineEven(int);
	bool catWin( sf::Vector2<int> );
	bool isValid(int);
	sf::Vector2<int> moveCatRandomly(std::vector<std::vector<sf::CircleShape>>, sf::Vector2<int>);


	sf::Sprite m_sprite;
	bool m_reachedTheExit = false;
	bool m_trapped = false;

};
