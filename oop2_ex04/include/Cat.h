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

	bool ReachedTheExit() { return m_reachedTheExit; };
	void resetReachedTheExit() { m_reachedTheExit = false; };
	void move(std::vector<std::vector<sf::CircleShape>>) ;
	void draw (sf::RenderWindow& window) const {window.draw(m_sprite);}
	sf::Vector2<int> minDistance(std::vector<std::vector<sf::CircleShape>> grid);
	void setPos(sf::Vector2f pos) { m_sprite.setPosition(pos); };
	sf::Vector2f getPos() { return m_sprite.getPosition(); };
	void resetMatrix(std::vector<std::vector<sf::Vector2<int>>> &);
	sf::Vector2<int> calaulateFirstMove(std::vector<std::vector<sf::Vector2<int>>>, 
		sf::Vector2<int>, sf::Vector2<int>);
	bool canMove(std::vector<std::vector<sf::CircleShape>> grid, sf::Vector2<int> source);

private:
	sf::Sprite m_sprite;
	bool isValid(int);
	bool m_reachedTheExit = false;
	bool isLineEven(int);
};
