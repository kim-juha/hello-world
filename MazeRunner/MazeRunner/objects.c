#include "objects.h"
#include <stdlib.h>
#include <string.h>

typedef struct object_list
{
	int* data;
	int size;
	int capacity;
} Object_list;

Object_list active_objects[MAX_OBJECTS];

int generate_id(Object object)
{
	Object_list* list = &active_objects[object];
	for (int i = 0; i < list->size; ++i)
	{
		if (list->data[i] == 0)
			return object * 1000 + (i + 1);
	}
	return 0;
}

int create_object(Object object)
{
	Object_list* list = &active_objects[object];

	if (list->size >= list->capacity)
	{
		int* temp = list->data;
		list->capacity = list->size * 2;
		list->data = malloc(sizeof(int) * list->capacity);
		memcpy(list->data, temp, list->size);
		free(temp);
	}

	int id = generate_id(object);
	list->data[list->size] = id;
	++list->size;

	return id;
}

void destroy_object(int id)
{
	for (int i = EMPTY + 1; i < MAX_OBJECTS; ++i)
	{
		int sentinel = i * 1000;
		if (id <= sentinel)
		{
			int index = id - sentinel - 1;
			active_objects[i].data[index] = 0;
		}
	}
}