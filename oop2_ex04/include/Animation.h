#pragma once
#include "MovingObject.h"
class Animation
{
public:
	Animation(sf::Texture *,sf::Vector2u ,float);
	~Animation() {};

	void Update(int row, float deltaTime,bool faseRight );
sf::IntRect uvRect;

private:
	sf::Vector2u m_imageCount;
	sf::Vector2u m_currentImage;
	//
	sf::Vector2f m_currDirection;
	//
	float m_totalTime;
	float m_switchTime;
};