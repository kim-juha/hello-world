#pragma once

typedef enum object
{
	EMPTY,
	WALL,
	PLAYER,

	MAX_OBJECTS
} Object;

int create_object(Object object);
void destroy_object(int id);

char get_object_surface(int id);