#include "Cat.h"


// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

//Cat::Cat(sf::Vector2u imageCount, float switchTime, float speed)
//	//m_texture(FileManager::p2FileManager().getCatTexture()),
//	//m_animation(m_texture, imageCount, switchTime)
//{
//	auto m_pTexture = FileManager::p2FileManager().getCatTexture();
//	m_sprite.setTexture(*m_texture);
//	m_sprite.scale(BUTTONS_SCALE);
//
//
//
//
//	////for animation
//	//m_speed = speed;
//	//m_faceRight =  true;
//	//m_row = 0;
//
//	////m_body.setSize(sf::Vector2(50.0f, 75.0f));
//	//m_body.setPosition(206.0f, 206.0f);
//	//m_body.setTexture(m_texture);
//	////m_body.setTextureRect(m_animation.uvRect);
//
//
//
//
//}
//---------------------------------------------------
Cat::Cat()
{
	auto m_pTexture = FileManager::p2FileManager().getCatTexture();
	m_sprite.setTexture(*m_pTexture);
	m_sprite.scale(MOVING_OBJ_SCALE);
}


void Cat::move(std::vector<std::vector<sf::CircleShape>> grid, sf::Time& deltaTime)
{

	//m_currDirection = sf::Vector2f(getNextMove(grid, m_sprite.getPosition()));
	m_currDirection = sf::Vector2f(getNextMove(grid, m_sprite.getPosition()));
	if (m_currDirection != sf::Vector2f(-1, -1))
		m_sprite.setPosition(grid[m_currDirection.x][m_currDirection.y].getPosition());
	//{
	//	updateAnimation(m_currDirection, m_body.getPosition(), deltaTime);
	//	m_sprite.setPosition(grid[m_currDirection.x][m_currDirection.y].getPosition());
	//	
	//}

	//updateAnimation();
	//m_sprite.move(m_currDirection* BASE_SPEED * deltaTime.asSeconds());
}

//---------------------------------------------------
//void Cat::updateAnimation(sf::Vector2f cuurDir, sf::Vector2f currPos, sf::Time& deltaTime)
//{
//	sf::Vector2f movement(0.0f, 0.0f);
//
//	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//		movement.x -= m_speed * deltaTime;
//	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//		movement.x += (m_speed * deltaTime;*/
//
//	if (movement.x == 0.0f)
//		m_row = 0;
//	else
//	{
//		m_row = 1;
//
//		if (movement.x > 0.0f)
//			m_faceRight = true;
//		else
//			m_faceRight = false
//	}
//
//	m_animation.Update(m_row, deltaTime, m_faceRight);
//	m_body.setTexture(m_animation.uvRect);
//	body.move(movement);
//		
//	}
//		
//
//
//	/*if ((isLineEven(currPos.x))
//	{
//		if(currPos.x EVENDVec[LEFT] == cuurDir)
//			if (m_faceRight)
//			{
//				m_faceRight
//			}
//	}*/
//	//const sf::Vector2i EVENDVec[] = {{0,-1}, {0,1}, {-1,-1}, {-1,0},{1,-1},{1,0}};
//	//const sf::Vector2i ODDDVec[] = { {0,-1}, {0,1} ,{-1,0}, {-1,1}, {1,0}, {1,1} };
//	//LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT
//}

