#pragma once

#include <stdbool.h>

typedef struct player_t
{
	char symbol;

	int pos_x;
	int pos_y;

	bool has_key;
} Player;

Player* create_player();
void destroy_player(Player* player);

void update_player(Player* player, float delta_time);
void render_player(Player* player);