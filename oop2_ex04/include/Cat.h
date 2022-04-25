#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
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
	std::vector<sf::Vector2<int>> minDistance(std::vector<std::vector<sf::CircleShape>> grid);
	void setPos(sf::Vector2f pos) { m_sprite.setPosition(pos); };
	sf::Vector2f getPos() { return m_sprite.getPosition(); };

private:
	sf::Sprite m_sprite;
	bool m_reachedTheExit = false;
};
