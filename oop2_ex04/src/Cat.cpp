#include "Cat.h"


// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

Cat::Cat()
{
	auto m_pTexture = FileManager::p2FileManager().getCatTexture();
	m_sprite.setTexture(*m_pTexture);
	m_sprite.scale(BUTTONS_SCALE);
}
//---------------------------------------------------

void Cat::move(std::vector<std::vector<sf::CircleShape>> grid)
{
	sf::Vector2<int> moveTo = findAPath(grid);
	if (moveTo != sf::Vector2<int>(-1, -1))
		m_sprite.setPosition(grid[moveTo.x][moveTo.y].getPosition());
}
//---------------------------------------------------

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
//---------------------------------------------------

bool Cat::isValid(int ind)
{
	return ind >= 0 && ind < BOARD_LEN;
}
//---------------------------------------------------

bool Cat::isLineEven(int line)
{
	return line % 2 == 0;
	std::cout << line;
}
//---------------------------------------------------

sf::Vector2<int> Cat::findAPath(std::vector<std::vector<sf::CircleShape>> grid)
{
	std::vector<std::vector<sf::Vector2<int>>> discover;
	sf::Vector2<int> source;
	bool visited[BOARD_LEN][BOARD_LEN];	// To keep track of visited vertex. Marking
	// blocked cells as visited.
	std::queue<sf::Vector2<int>> q;
	sf::Vector2<int> p;

	resetMatrix(discover);
	fillVisitedAndFindSource(grid, source, visited);

	if(catWin( source))
		return { -1,-1 };

	if (!canMove(grid, source))
		return { -1,-1 };

	// applying BFS on matrix cells starting from source
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
		checkDirection(p.x, p.y -1, visited, q, discover, p);

		// moving right 
		checkDirection(p.x , p.y + 1, visited, q, discover, p);

		//moving up left
		if (isLineEven(p.x))
			checkDirection(p.x - 1, p.y-1, visited, q, discover, p);
		else
			checkDirection(p.x - 1, p.y, visited, q, discover, p);
		
		//moving up right
			if (isLineEven(p.x))
				checkDirection(p.x - 1, p.y, visited, q, discover, p);
			else
				checkDirection(p.x - 1, p.y + 1, visited, q, discover, p);

		// moving down left 
			if (isLineEven(p.x))
				checkDirection(p.x + 1, p.y-1, visited, q, discover, p);
			else
				checkDirection(p.x + 1, p.y, visited, q, discover, p);

		// moving down right 
			if (isLineEven(p.x))
				checkDirection(p.x + 1, p.y, visited, q, discover, p);
			else
				checkDirection(p.x + 1, p.y + 1, visited, q, discover, p);	
	}
	return moveCatRandomly(grid, source);
}
//---------------------------------------------------

void Cat::checkDirection(int x, int y, bool visited[BOARD_LEN][BOARD_LEN] ,
	std::queue<sf::Vector2<int>>& q,
	std::vector<std::vector<sf::Vector2<int>>>& discover, sf::Vector2<int> p)
{
	if (isValid(y) && isValid(x) && visited[x][y] == false)
	{
		q.push(sf::Vector2<int>(x, y));
		visited[x][y] = true;
		discover[x][y] = sf::Vector2<int>(p.x, p.y);
	}
}
//---------------------------------------------------

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
//---------------------------------------------------

void Cat::fillVisitedAndFindSource(std::vector<std::vector<sf::CircleShape>> grid,
	sf::Vector2<int>& source, bool visited[BOARD_LEN][BOARD_LEN])
{

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
				source.x = i;
				source.y = j;
			}
		}
	}
}
//---------------------------------------------------

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
//---------------------------------------------------

bool Cat::catWin( sf::Vector2<int> source)
{
	if (source.x == 0 || source.x == 10 || source.y == 0 || source.y == 10)
	{
		m_reachedTheExit=true;
		return true;
	}
	return false;
}
//---------------------------------------------------

sf::Vector2<int> Cat::moveCatRandomly(std::vector<std::vector<sf::CircleShape>> grid
	, sf::Vector2<int> source)
{
	sf::Vector2<int> pos{ 0,0 };
	do
	{
		pos = grillDirection();
	} while (grid[pos.x+ source.x][pos.y+ source.y].getFillColor() == CLICKED_COLOR);
	pos += source;
	return pos;
}
//----------------------------------------------------

sf::Vector2<int> Cat::grillDirection() const
{
	int dir = rand() % 6;

	switch ((direction)dir)
	{
	case RIGHT:
		return  { 1, 0 };
	case LEFT:
		return { -1, 0 };
	case UP_LEFT:
		return  { 0, -1 };
	case UP_RIGHT:
		return { 1, -1 };
	case DOWN_LEFT:
		return { -1, 1 };
	case DOWN_RIGHT:
		return { 0, 1 };
	}
	return { 0, 0 };
}