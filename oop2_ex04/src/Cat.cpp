#include "Cat.h"


// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

#include <limits.h>
#include <stdio.h>

//---------------------------------------------------
//
void Cat::move(std::vector<std::vector<sf::CircleShape>> grid)
{
	if (canMove())
	{
		//(grid, m_sprite.)
    }
}

//canMove()
//{
//
//}


// C++ Code implementation for above problem
#include <bits/stdc++.h>
using namespace std;

#define N 11
#define M 11

// QItem for current location and distance
// from source location
class QItem {
public:
	int row;
	int col;
	int dist;
	QItem(int x, int y, int w)
		: row(x), col(y), dist(w)
	{
	}
};

int minDistance(std::vector<std::vector<sf::CircleShape>> grid)
{
	QItem source(0, 0, 0);

	// To keep track of visited QItems. Marking
	// blocked cells as visited.
	bool visited[N][M];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j].getFillColor() == CLICKED_COLOR)//cant pass them
				visited[i][j] = true;
			else
				visited[i][j] = false;

			// Finding the place tha cat standing on
			if (grid[i][j].getPosition() == this->m_sprite.getPosition())
			{
				source.row = i;
				source.col = j;
			}
		}
	}

	// applying BFS on matrix cells starting from source
	queue<QItem> q;
	q.push(source);
	visited[source.row][source.col] = true;
	while (!q.empty()) 
	{
		QItem p = q.front();
		q.pop();

		// Destination found;
		if (p.row==0|| p.row == 10||p.col == 0|| p.col==10)
			return p.dist;

		// moving up left
		if (p.row - 1 >= 0 &&
			visited[p.row - 1][p.col-1] == false) 
		{
			q.push(QItem(p.row - 1, p.col-1, p.dist + 1));
			visited[p.row - 1][p.col-1] = true;
		}

		// moving up right
		if (p.row - 1 >= 0 &&
			visited[p.row - 1][p.col + 1] == false) 
		{
			q.push(QItem(p.row - 1, p.col + 1, p.dist + 1));
			visited[p.row - 1][p.col+1] = true;
		}

		// moving down left 
		if (p.row + 1 < N &&
			visited[p.row + 1][p.col-1] == false) {
			q.push(QItem(p.row + 1, p.col-1, p.dist + 1));
			visited[p.row + 1][p.col-1] = true;
		}

		// moving down right
		if (p.row + 1 < N &&
			visited[p.row + 1][p.col+1] == false) {
			q.push(QItem(p.row + 1, p.col+1, p.dist + 1));
			visited[p.row + 1][p.col+1] = true;
		}

		// moving left
		if (p.col - 1 >= 0 &&
			visited[p.row][p.col - 1] == false) {
			q.push(QItem(p.row, p.col - 1, p.dist + 1));
			visited[p.row][p.col - 1] = true;
		}

		// moving right
		if (p.col + 1 < M &&
			visited[p.row][p.col + 1] == false) {
			q.push(QItem(p.row, p.col + 1, p.dist + 1));
			visited[p.row][p.col + 1] = true;
		}
	}
	return -1;
}

// Driver code
int main()
{
	char grid[N][M] = { { '0', '*', '0', 's' },
						{ '*', '0', '*', '*' },
						{ '0', '*', '*', '*' },
						{ 'd', '*', '*', '*' } };

	cout << minDistance(grid);
	return 0;
}
