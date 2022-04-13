
#include "Board.h"

// board c-tor 
Board::Board()
{
	
	m_movingRec.setSize(sf::Vector2f((float)P_SIZE, (float)P_SIZE));
	//m_toolbar.setToolbar(m_boardSize.x);
}

//set the board size
void Board::setBoard()
{
	/*m_grid.resize((int)m_boardSize.x);
	for (size_t i = 0; i < m_boardSize.x; i++)
		m_grid[i].resize((int)m_boardSize.y);*/
}

// draws the grid
void Board::drawGrid(sf::RenderWindow& window)
{
}

// draw all the relevent objects 
void Board::draw(sf::RenderWindow& window)
{
	/*drawGrid(window);
	window.draw(m_currSprite);
	m_toolbar.drawToolbar(window, m_boardSize.y);
	drawIcons(window);
	m_eraseMode ? window.draw(m_movingRec) : window.draw(m_movingIcon);*/
}

// in case the user clicked on the mouse
void Board::mouseButtonReleased(sf::Event event, sf::RenderWindow& window)
{
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;
	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));


}

////draw all the icons on the window
//void Board::drawIcons(sf::RenderWindow& window)
//{
//	for (size_t i = 0; i < m_boardSize.x; i++)
//		for (size_t j = 0; j < m_boardSize.y; j++)
//			if (m_grid[i][j] != nullptr)
//				m_grid[i][j]->draw(window, sf::Vector2f(((float)j) * P_SIZE,
//					((float)(i + 1)) * P_SIZE),
//					m_toolbar.getIconSprite(m_grid[i][j]->getShape()));
//}

void Board::mouseMoved(sf::Event event, sf::RenderWindow& window)
{

	int x = event.mouseMove.x;
	int y = event.mouseMove.y;

	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));
	x = ((int)pos.y / P_SIZE) - 1;
	y = (int)pos.x / P_SIZE;

	m_movingRec.setFillColor(sf::Color(176, 196, 222, 150));//the first
	
	m_movingRec.setPosition(pos);
	

	m_movingIcon.setPosition(pos);
	m_movingIcon.setColor(sf::Color(255, 255, 255, 125));
}

// checks if the mouse is in the window
bool Board::inWindow(sf::Event event)
{
	int x = event.mouseMove.x;
	int y = event.mouseMove.y;
	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));

	x = ((int)pos.y / P_SIZE) - 1;
	y = (int)pos.x / P_SIZE;

	if (y >= 0 && x >= 0 && x < m_boardSize.x && y < m_boardSize.y)
		return true;

	return false;
}





