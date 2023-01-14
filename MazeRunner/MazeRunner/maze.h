#pragma once

typedef struct maze_t
{
	int** data;
	int width;
	int height;
} Maze;

Maze* create_maze(int level);
void destroy_maze(Maze* maze);

void set_object_in_maze(Maze* maze, int x, int y, int id);
int get_object_in_maze(Maze* maze, int x, int y);