
#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include "Board.h"
using std::vector;



class Cat :
{
public:
	bool ReachedTheExit() { return m_reachedTheExit; };
	void resetReachedTheExit() { m_reachedTheExit = false; };
	void move(std::vector<std::vector<sf::CircleShape>>) {};
	void draw() {};
	void setPos(sf::Vector2f pos) { m_sprite.setPosition(pos)};
	sf::Vector2f getPos() {return m_sprite.getPosition()};

private:
	sf::Sprite m_sprite;
	bool m_reachedTheExit = false;
};
