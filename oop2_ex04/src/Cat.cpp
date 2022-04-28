#include "Cat.h"


// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

#include <limits.h>
#include <stdio.h>
Cat::Cat()
{
	auto m_pTexture = FileManager::p2FileManager().getCatTexture();
	m_sprite.setTexture(*m_pTexture);
	m_sprite.scale(BUTTONS_SCALE);
}
//---------------------------------------------------
//
void Cat::move(std::vector<std::vector<sf::CircleShape>> grid)
{
	sf::Vector2<int> moveTo = findAPath(grid);
	if (moveTo != sf::Vector2<int>(-1, -1))
		m_sprite.setPosition(grid[moveTo.x][moveTo.y].getPosition());
}

bool Cat::canMove(std::vector<std::vector<sf::CircleShape>> grid, sf::Vector2<int> source)
{
	if ((grid[source.x - 1][source.y].getFillColor() == CLICKED_COLOR)
		&& (grid[source.x + 1][source.y].getFillColor() == CLICKED_COLOR)
		&& (grid[source.x][source.y - 1].getFillColor() == CLICKED_COLOR)
		&& (grid[source.x - 1][source.y + 1].getFillColor() == CLICKED_COLOR)
		&& (grid[source.x + 1][source.y - 1].getFillColor() == CLICKED_COLOR)
		&& (grid[source.x][source.y + 1].getFillColor() == CLICKED_COLOR))
	{
		m_trapped = true;
		return false;
	}
	return true;
}

bool Cat::isValid(int ind)
{
	return ind >= 0 && ind < BOARD_LEN;
}

bool Cat::isLineEven(int line)
{
	return line % 2 == 0;
	std::cout << line;
}


// C++ Code implementation for above problem
#include <deque>  
#include <queue> 
using namespace std;

sf::Vector2<int> Cat::findAPath(std::vector<std::vector<sf::CircleShape>> grid)
{
	//save for each vertex which vertex discovered him
	std::vector<std::vector<sf::Vector2<int>>> discover;
	//save the cat current place on the grid
	sf::Vector2<int> source;
	// To keep track of visited vertex. Marking
	// blocked cells as visited.
	bool visited[BOARD_LEN][BOARD_LEN];

	resetMatrix(discover);

	for (int i = 0; i < BOARD_LEN; i++)
	{
		for (int j = 0; j < BOARD_LEN; j++)
		{
			if (grid[i][j].getFillColor() == CLICKED_COLOR)//cant pass them
				visited[i][j] = true;
			else
				visited[i][j] = false;

			// checking if the current place is were the cat standing on
			if (grid[i][j].getPosition() == this->m_sprite.getPosition())
			{
				source.x=i;
				source.y = j;
			}
		}
	}	 
	

	if(catWin( source))
		return { -1,-1 };

	//if cat encircled 
	if (!canMove(grid, source))
		return { -1,-1 };

	// applying BFS on matrix cells starting from source
	std::queue<sf::Vector2<int>> q;
	sf::Vector2<int> p;
	q.push(source);
	visited[source.x][source.y] = true;

	while (!q.empty()) 
	{
		p = q.front();
		q.pop();

		// Destination found;
		if (p.x == 0 || p.x == 10 || p.y == 0 || p.y == 10)
		{
			if (source == discover[p.x][p.y])
				return p;
			return calaulateFirstMove(discover, source, discover[p.x][p.y]);
		}

		 //moving left
		if (isValid(p.y - 1)  && isValid(p.x)&&  visited[p.x][p.y - 1] == false)
		{
			q.push(sf::Vector2<int>(p.x, p.y - 1));
			visited[p.x][p.y - 1] = true;
			discover[p.x][p.y - 1] = sf::Vector2<int>(p.x, p.y);
		}

		// moving right  
		if (isValid(p.y + 1) && isValid(p.x) && visited[p.x][p.y+1] == false)
		{
			q.push(sf::Vector2<int>(p.x, p.y + 1));
			visited[p.x][p.y+1] = true;
			discover[p.x][p.y + 1] = sf::Vector2<int>(p.x, p.y);
		}

		//moving up left
		if (isValid(p.x - 1))
		{
			if (isLineEven(p.x))
				if (isValid(p.y - 1) && visited[p.x - 1][p.y - 1] == false)
				{
					q.push(sf::Vector2<int>(p.x - 1, p.y - 1));
					visited[p.x - 1][p.y - 1] = true;
					discover[p.x - 1][p.y - 1] = sf::Vector2<int>(p.x, p.y);
				}
		}
		else
		{
			if (visited[p.x - 1][p.y] == false)
			{
				q.push(sf::Vector2<int>(p.x - 1, p.y));
				visited[p.x - 1][p.y] = true;
				discover[p.x - 1][p.y] = sf::Vector2<int>(p.x, p.y);
			}
		}
				

		//moving up right
		if (isValid(p.x - 1))
			if (isLineEven(p.x))
			{
				if (visited[p.x - 1][p.y] == false)
				{
					q.push(sf::Vector2<int>(p.x - 1, p.y));
					visited[p.x - 1][p.y] = true;
					discover[p.x - 1][p.y] = sf::Vector2<int>(p.x, p.y);
				}
			}
				
			else
			{
				if (isValid(p.y + 1) && visited[p.x - 1][p.y + 1] == false)
				{
					q.push(sf::Vector2<int>(p.x - 1, p.y + 1));
					visited[p.x - 1][p.y + 1] = true;
					discover[p.x - 1][p.y + 1] = sf::Vector2<int>(p.x, p.y);
				}
			}
				
		 
		// moving down left 
		if (isValid(p.x + 1) )
			if (isLineEven(p.x))
			{
				if (isValid(p.y - 1) && visited[p.x + 1][p.y - 1] == false)
				{
					q.push(sf::Vector2<int>(p.x + 1, p.y - 1));
					visited[p.x + 1][p.y - 1] = true;
					discover[p.x + 1][p.y - 1] = sf::Vector2<int>(p.x, p.y);
				}
			}
				
			else
			{
				if (visited[p.x + 1][p.y] == false)
				{
					q.push(sf::Vector2<int>(p.x + 1, p.y));
					visited[p.x + 1][p.y] = true;
					discover[p.x + 1][p.y] = sf::Vector2<int>(p.x, p.y);
				}
			}
				
		
		// moving down right 
		if (isValid(p.x + 1) )
			if (isLineEven(p.x))
			{
				if (visited[p.x + 1][p.y] == false)
				{
					q.push(sf::Vector2<int>(p.x + 1, p.y));
					visited[p.x + 1][p.y] = true;
					discover[p.x + 1][p.y] = sf::Vector2<int>(p.x, p.y);
				}
			}
				
			else
			{
				if (isValid(p.y + 1) && visited[p.x + 1][p.y + 1] == false)
				{
					q.push(sf::Vector2<int>(p.x + 1, p.y + 1));
					visited[p.x + 1][p.y + 1] = true;
					discover[p.x + 1][p.y + 1] = sf::Vector2<int>(p.x, p.y);
				}
			}
				
	}
	return moveCatRandomly(grid, source);
}


void Cat::resetMatrix(std::vector<std::vector<sf::Vector2<int>>> & discover)
{
	for (size_t i = 0; i < BOARD_LEN; i++)
	{
		std::vector<sf::Vector2<int>> currRow;

		for (size_t j = 0; j < BOARD_LEN; j++)
		{
			currRow.push_back({-1, -1});
		}
		discover.push_back(currRow);
	}
}

sf::Vector2<int> Cat::calaulateFirstMove(std::vector<std::vector<sf::Vector2<int>>> discover,
	sf::Vector2<int> source,sf::Vector2<int> foundExit)
{
	sf::Vector2<int> temp = foundExit;
	sf::Vector2<int> firstStep = temp;

	while (temp != source)
	{
		firstStep = temp;
		temp = discover[temp.x][temp.y];
	}
	return firstStep;
}


bool Cat::catWin( sf::Vector2<int> source)
{
	if (source.x == 0 || source.x == 10 || source.y == 0 || source.y == 10)
	{
		m_reachedTheExit=true;
		return true;
	}
	return false;
}

sf::Vector2<int> Cat::moveCatRandomly(std::vector<std::vector<sf::CircleShape>> grid
	, sf::Vector2<int> source)
{
	//sf::Vector2<int> pos{ 0,0 };
	//do
	//{
	//	pos.x = rand() % 2;
	//	pos.y = rand() % 2;
	//} while (pos.x == 5 && pos.y == 5);//while its not in the cat place
	return { -1,-1 };
}