#include "cub3d.h"

void init_player(t_player *player)
{
	player->x = 10.5; //recuperer du parsing
	player->y = 5.5; // recuperer du parsing

	player->dir_x = 0; // recuperer dans parsing
	player->dir_y = -1;	// recuperer dans parsing (actuellemt regarde vers le nord)
	player->plane_x = 0.66;
	player->plane_y = 0;

	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;

	player->left_rotation = false;
	player->right_rotation = false;
}
