
#include "Board.h"

// board c-tor 
Board::Board()
{
	//m_movingCircle.setRadius(35);
	setBoard();
}

//set the board
void Board::setBoard()
{
	setTitle();
	setGrid();
}

void Board::setTitle()
{
	m_title.loadFromFile("Title.png");
	m_spriteTitle.setTexture(m_title);
	m_spriteTitle.setPosition(400, 0);
}


// draws the grid
void Board::setGrid()
{
	sf::Vector2f pos = { 35, 50 };
	for (size_t i = 0; i < BOARD_LEN; i++)
	{
		std::vector<sf::CircleShape> circleRow;
		for (size_t j = 0; j < BOARD_LEN; j++)
		{
			sf::CircleShape circle(35);
			circle.setPosition(pos);
			circle.setFillColor(sf::Color::Green);
			circleRow.push_back(circle);
			pos.x += 75;
		}
		m_board.push_back(circleRow);
		pos.y += 75;
		if (i % 2 == 0) 
			pos.x = 60;
		else 
			pos.x = 35;
	}
}
// draw all the relevent objects 
void Board::draw(sf::RenderWindow& window)const
{
	window.draw(m_spriteTitle);
	drawGrid(window);
	//window.draw(m_movingCircle);
}

void Board::drawGrid(sf::RenderWindow& window)const
{
	for (auto i : m_board)
	{
		for (auto j : i)
			window.draw(j);
	}
}

// in case the user clicked on the mouse
void Board::mouseButtonReleased(sf::Event event, sf::RenderWindow& window)
{
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;
	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));
	//int count = 0;

	/* Mouse click on Circle */
	for (auto i : m_board)
	{
		for (auto j : i)
		{
			if (j.getFillColor() == sf::Color::Green)
			{
				/* if mouse position is in circle range : pos.x < mouse.x < pos.x+radius and pos.y < mouse.y < pos.y+radius */
				if (pos.x >j.getPosition().x && pos.x < (j.getPosition().x + (j.getRadius() * 2)) &&
					pos.y > j.getPosition().y && pos.y < (j.getPosition().y + (j.getRadius() * 2)))
				{
					j.setFillColor(sf::Color::Black);
					m_clickCount++;
					/* do the cat move stuff*/
				}
			}
		}
	}
}

void Board::mouseMoved(sf::Event event, sf::RenderWindow& window)
{

	int x = event.mouseMove.x;
	int y = event.mouseMove.y;

	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));
	x = ((int)pos.y / P_SIZE) - 1;
	y = (int)pos.x / P_SIZE;

	//m_movingCircle.setFillColor(sf::Color(176, 196, 222, 150));//the first
	//m_movingCircle.setPosition(pos);
}

// checks if the mouse is in the window
bool Board::inWindow(sf::Event event)
{
	int x = event.mouseMove.x;
	int y = event.mouseMove.y;
	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));

	x = ((int)pos.y / P_SIZE) - 1;
	y = (int)pos.x / P_SIZE;

	if (y >= 0 && x >= 0 && x < BOARD_LEN && y < BOARD_LEN)
		return true;
	return false;
}
