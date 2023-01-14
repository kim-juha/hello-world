#include "rendering.h"

typedef struct model_data
{
	int object_id;
	Model model;
} Model_data;


Model_data model_data[100];
int size;

void set_object_model(int id, Model model)
{
	for (int i = 0; i < 100; ++i)
	{
		if (model_data[i].object_id == 0)
		{
			model_data[i].object_id = id;
			model_data[i].model = model;
		}
	}
}

Model get_object_model(int id)
{
	for (int i = 0; i < 100; ++i)
	{
		if (model_data[i].object_id == id)
		{
			return model_data[i].model;
		}
	}
	return 0;
}
