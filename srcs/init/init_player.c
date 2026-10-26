#include "cub3d.h"

void init_player(t_player *player)
{
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;

	player->left_rotation = false;
	player->right_rotation = false;
}
