#include "maze.h"
#include <stdlib.h>

Maze* create_maze(int level)
{
	Maze* maze = (Maze*)malloc(sizeof(Maze));
	
	// height
	maze->data = (int**)malloc(sizeof(int*) * 10);
	for (int i = 0; i < 10; ++i)
	{
		// width
		maze->data[i] = (int*)malloc(sizeof(int) * 10);
	}
	maze->width = 10;
	maze->height = 10;

	return maze;
}

void destroy_maze(Maze* maze)
{
	for (int i = 0; i < maze->height; ++i)
	{
		free(maze->data[i]);
	}
	free(maze->data);
	free(maze);
}

void set_object_in_maze(Maze* maze, int x, int y, int id)
{
	maze->data[y][x] = id;
}

int get_object_in_maze(Maze* maze, int x, int y)
{
	return maze->data[y][x];
}