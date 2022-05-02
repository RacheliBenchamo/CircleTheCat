#include "Cat.h"


// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

Cat::Cat(sf::Vector2u imageCount, float switchTime, float speed):
	m_texture(FileManager::p2FileManager().getCatTexture()),
	m_animation(m_texture, imageCount, switchTime)
{
	//auto m_pTexture = FileManager::p2FileManager().getCatTexture();
	m_sprite.setTexture(*m_texture);
	m_sprite.scale(BUTTONS_SCALE);

	m_speed = speed;
	m_faceRight =  true;
	m_row = 0;

	m_body.setSize(sf::Vector2(50.0f, 75.0f));
	m_body.setPosition(206.0f, 206.0f);
	m_body.setTexture(m_texture);
	m_body.setTextureRect(m_animation.uvRect);




}
//---------------------------------------------------
//Cat::Cat()
//{
//	auto m_pTexture = FileManager::p2FileManager().getCatTexture();
//	m_sprite.setTexture(*m_pTexture);
//	m_sprite.scale(BUTTONS_SCALE);
//}


void Cat::move(std::vector<std::vector<sf::CircleShape>> grid, sf::Time& deltaTime)
{

	//m_currDirection = sf::Vector2f(getNextMove(grid, m_sprite.getPosition()));
	m_currDirection = sf::Vector2f(getNextMove(grid, m_body.getPosition()));
	if (m_currDirection != sf::Vector2f(-1, -1))
		//m_sprite.setPosition(grid[m_currDirection.x][m_currDirection.y].getPosition());
	{
		//updateAnimation(m_currDirection, m_body.getPosition());
		m_body.setPosition(grid[m_currDirection.x][m_currDirection.y].getPosition());
		
	}

	//updateAnimation();
	//m_sprite.move(m_currDirection* BASE_SPEED * deltaTime.asSeconds());
}
//---------------------------------------------------
//void Cat::updateAnimation(sf::Vector2f cuurDir, sf::Vector2f dir)
//{
//	if((isLineEven(dir.x) &&
//}

//void Cat::updateAnimation()
//{
	/*if (m_currDirection == DVec[DOWN])
	{
		m_animationRow = 0;
		updateSpriteCol();
	}
	else if (m_currDirection == DVec[LEFT])
	{
		m_animationRow = 1;
		updateSpriteCol();
	}
	else if (m_currDirection == DVec[RIGHT])
	{
		m_animationRow = 2;
		updateSpriteCol();
	}
	else if (m_currDirection == DVec[UP])
	{
		m_animationRow = 3;
		updateSpriteCol();
	}*/
//}
