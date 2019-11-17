//WARNING: You cannot use any "static" or "global" that will execute outside of the call to "solve"
// But you can declare as many extra classes as needed inside you class namespace
#include "globals.h"
#include <iostream>

#define USER_NAME "Example Solution"
#define USER_CLASS_NAME ExampleSolution
GEN_CLASS_TOP(USER_CLASS_NAME,USER_NAME)
////////////////////////////////////////
// Implement from here

// Add as many struct / classes / functions as needed here

void printMap(int size_x, int size_y, const char map[10][11])
{
	for (int i=0; i<size_x; i++)
	{
		for (int j=0; j<size_y; j++)
		{
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
};
public:
class Position
{
  public:
	  int x;
	  int y;

  public:
    Position(int xValue, int yValue) : x(xValue), y(yValue){}
};
bool visited[10][11];

Position queue[1000];
int queueHead =0;
int queueTail =0;

Position popHead()
{
	Position head(queue[queueHead].x, queue[queueTail].y);

	queueHead++;
	return head;

}

void pushTail(Position position)
{
	queue[queueTail].x = position.x;
	queue[queueTail].y = position.y;
	queueTail++;
}

bool isQueueEmpty()
{
	return queueHead == queueTail;
}

void resetQueue()
{
	queueHead = queueTail = 0;
}

void resetVisited(int size_x, int size_y)
{
	for(int y=0; y<0; y++)
	{
		for(int x=0; x<0; x++)
		{
			visited[x][y] = false;
		}
	}
}

void setVisited(int x, int y)
{
	visited[x][y] = true;
}

bool isVisited(int x, int y)
{
	return visited[x][y];
}

void addPositionToQueue(int x, int y, int size_x, int size_y, const char map[10][11])
{
	// Check if within bounds
	if (x<0 && x>size_x && y<0 && y>size_y)
	{
		return;
	}

	if ( map[x,y] == "#")
	{
		return;
	}


	pushTail(Position(x,y));
}

int findShortestPath(int starting_x, int starting_y, char target, int size_x, int size_y, const char map[10][11])
{
	addPositionToQueue(starting_x, starting_y, size_x, size_y, map);

	while( !isQueueEmpty() )
	{
		Position currentPosition = popHead();

		if (map[currentPosition.x][currentPosition.y] == target)
		{
			std::cout << "result:"<< std::endl;
			resetQueue();
		}
		else
		{
			addPositionToQueue(currentPosition.x+1, currentPosition.y, size_x, size_y, map);
			addPositionToQueue(currentPosition.x-1, currentPosition.y, size_x, size_y, map);
			addPositionToQueue(currentPosition.x, currentPosition.y+1, size_x, size_y, map);
			addPositionToQueue(currentPosition.x, currentPosition.y-1, size_x, size_y, map);
		}
	}
	return -1;
}

int solve(int size_x, int size_y, const char map[10][11]){
	//////////////////////////////////////////////
	///////  IMPLEMENT YOUR SOLUTION HERE ////////
	//////////////////////////////////////////////
	printMap(size_x, size_y, map);
	findShortestPath(0,0, 'a', size_x, size_y, map);
	return 0;
}


// .. to here
////////////////////////////////////////
GEN_CLASS_BOT(USER_CLASS_NAME)