#include "player.h"
#include <stdlib.h>

Player* create_player()
{
	return malloc(sizeof(Player));
}

void destroy_player(Player* player)
{
	free(player);
}


void update_player(Player* player, float delta_time)
{
}

void render_player(Player* player)
{

}
