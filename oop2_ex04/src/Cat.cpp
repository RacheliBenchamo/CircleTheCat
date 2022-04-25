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
	//if (canMove())
	//{
	//	//(grid, m_sprite.)
 //   }
}

//canMove()
//{
//
//}


// C++ Code implementation for above problem
#include <deque>  
#include <queue> 
using namespace std;

std::vector<sf::Vector2<int>> Cat::minDistance(std::vector<std::vector<sf::CircleShape>> grid)
{
	//QItem source(0, 0, 0);
	sf::Vector2<int> source(0, 0);
	// To keep track of visited QItems. Marking
	// blocked cells as visited.
	bool visited[BOARD_LEN][BOARD_LEN];

	for (int i = 0; i < BOARD_LEN; i++)
	{
		for (int j = 0; j < BOARD_LEN; j++)
		{
			if (grid[i][j].getFillColor() == CLICKED_COLOR)//cant pass them
				visited[i][j] = true;
			else
				visited[i][j] = false;

			// Finding the place tha cat standing on
			if (grid[i][j].getPosition() == this->m_sprite.getPosition())
			{
				source.x=i;
				source.y = j;
			}
		}
	}

	// applying BFS on matrix cells starting from source
	std::vector<sf::Vector2<int>> way;
	std::queue<sf::Vector2<int>> q;
	q.push(source);

	visited[source.x][source.y] = true;

	while (!q.empty()) 
	{
		sf::Vector2<int> p = q.front();
		q.pop();

		// Destination found;
		if (p.x==0|| p.x == 10||p.y == 0|| p.y==10)
			return way;

		// moving up left
		if (p.x - 1 >= 0 && visited[p.x - 1][p.y-1] == false) 
		{
			q.push(sf::Vector2<int>(p.x - 1, p.y - 1));
			way.push_back(sf::Vector2<int>(p.x - 1, p.y - 1));
			visited[p.x - 1][p.y-1] = true;
		}

		// moving up right
		if (p.x - 1 >= 0 && visited[p.x - 1][p.y + 1] == false) 
		{
			q.push(sf::Vector2<int>(p.x - 1, p.y + 1));
			way.push_back(sf::Vector2<int>(p.x - 1, p.y + 1));
			visited[p.x - 1][p.y+1] = true;
		}

		// moving down left 
		if (p.x + 1 < BOARD_LEN && visited[p.x + 1][p.y-1] == false)
		{
			q.push(sf::Vector2<int>(p.x + 1, p.y - 1));
			way.push_back(sf::Vector2<int>(p.x + 1, p.y - 1));
			visited[p.x + 1][p.y-1] = true;
		}

		// moving down right
		if (p.x + 1 < BOARD_LEN && visited[p.x + 1][p.y+1] == false)
		{
			q.push(sf::Vector2<int>(p.x+1, p.y + 1));
			way.push_back(sf::Vector2<int>(p.x + 1, p.y + 1));
			visited[p.x + 1][p.y+1] = true;
		}

		// moving left
		if (p.y - 1 >= 0 && visited[p.x][p.y - 1] == false) 
		{
			q.push(sf::Vector2<int>(p.x, p.y + 1));
			way.push_back(sf::Vector2<int>(p.x, p.y - 1));
			visited[p.x][p.y - 1] = true;
		}

		// moving right
		if (p.x + 1 < BOARD_LEN && visited[p.x][p.y + 1] == false) 
		{
			q.push(sf::Vector2<int>(p.x, p.y + 1));
			way.push_back(sf::Vector2<int>(p.x, p.y + 1));
			visited[p.x][p.y + 1] = true;
		}
	}
	//return -1;
}


