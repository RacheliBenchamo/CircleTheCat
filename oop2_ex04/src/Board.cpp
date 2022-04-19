
#include "Board.h"

// board c-tor 
Board::Board()
{
	setBoard();
}
 
//set the board
void Board::setBoard()
{
	setGrid();
	//setColored()..for(i<m_maxColoredCircles)
	// gril place
	//m_grid[i][j].setFillColor(CLICKED_COLOR);
	//m_grid[i][j].setOutlineColor(BASE_COLOR);
	//setCat();
}

// draws the grid
void Board::setGrid()
{
	sf::Vector2f pos = { ODD_DISTANCE, 150 };
	for (size_t i = 0; i < BOARD_LEN; i++)
	{
		std::vector<sf::CircleShape> currRow;
		for (size_t j = 0; j < BOARD_LEN; j++)
		{
			sf::CircleShape circle(CIRCLE_RADIUS);
			circle.setPosition(pos);
			circle.setFillColor(BASE_COLOR);
			circle.setOutlineColor(CLICKED_COLOR);
			circle.setOutlineThickness(2);
			currRow.push_back(circle);
			pos.x += CIRCLE_DISTANCE;
		}
		m_grid.push_back(currRow);
		pos.y += CIRCLE_DISTANCE;
		if (i % 2 == 0) 
			pos.x = EVEN_DISTANCE;
		else 
			pos.x = ODD_DISTANCE;
	}
	
}
// draw all the relevent objects 
void Board::draw(sf::RenderWindow& window)const
{
	drawGrid(window);
	//window.draw(m_cat);
	//window.draw(m_movingCircle);
}

void Board::drawGrid(sf::RenderWindow& window)const
{
	int r = 1;
	for (auto i : m_grid)
	{
		for (auto j : i)
		{
			window.draw(j);
		}
	}
}

// in case the user clicked on the mouse
void Board::mouseButtonReleased(sf::Event event, sf::RenderWindow& window)
{
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;

	sf::Vector2f pos((float)(x ), (float)(y));

	// Mouse click on circle
	for (size_t i = 0; i < BOARD_LEN; i++)
		for (size_t j = 0; j < BOARD_LEN; j++)
		{
			if (m_grid[i][j].getFillColor() == BASE_COLOR)
			{
				/* if mouse position is in circle range : pos.x < mouse.x < pos.x+radius and pos.y < mouse.y < pos.y+radius */
				if (pos.x > m_grid[i][j].getPosition().x &&
					pos.x < (m_grid[i][j].getPosition().x + (m_grid[i][j].getRadius() * 2)) &&
					pos.y > m_grid[i][j].getPosition().y &&
					pos.y < (m_grid[i][j].getPosition().y + (m_grid[i][j].getRadius() * 2)))
				{
					m_grid[i][j].setFillColor(CLICKED_COLOR);
					m_grid[i][j].setOutlineColor(BASE_COLOR);
					m_clickCount++;
					/* do the cat move stuff*/
				}
			}
		}
}

void Board::restartLevel()
{
	//setboard
    //fill color
}
void Board::startNewLevel()
{
	//setboard
	//maxcircl-2;
	//gril colored circle and check that its not in 6 6
	//fill color
}
//fill color{
//m_grid[vector.i.x][vector.i.y].setFillColor(CLICKED_COLOR);
//m_grid[i][j].setOutlineColor(BASE_COLOR);