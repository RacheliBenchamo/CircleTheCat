#pragma once
#include "MovingObject.h"
#include "Animation.h"
class Cat:public MovingObject
{
public:
	//Cat();
	Cat(sf::Vector2u, float,float);
	~Cat() {};

	void move(std::vector<std::vector<sf::CircleShape>>, sf::Time& deltaTime) ;
	//void draw (sf::RenderWindow& window) const {window.draw(m_sprite);}
	void draw(sf::RenderWindow& window) const { window.draw(m_body); }
	//void setPos(sf::Vector2f pos) { m_sprite.setPosition(pos); }
	//m_body.setPosition(grid[m_currDirection.x][m_currDirection.y].getPosition());
	void setPos(sf::Vector2f pos) { m_body.setPosition(pos); }
	sf::Vector2f getPos() { return  m_body.getPosition(); };

private:
	//void updateAnimation();
	//void updateAnimation(sf::Vector2f, sf::Vector2f);
	
	sf::Sprite m_sprite;
	sf::Vector2f m_currDirection;


	sf::RectangleShape m_body;
	const sf::Texture *m_texture;
	Animation m_animation;
	unsigned int m_row;
	float m_speed;
	bool m_faceRight;

};
