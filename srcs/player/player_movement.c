#include "cub3d.h"


static void player_walk(t_player *player, float speed)
{
	if(player->key_up)
	{
		player->x += player->dir_x * speed;
		player->y += player->dir_y * speed;
	}

	if(player->key_down)
	{
		player->x -= player->dir_x * speed;
		player->y -= player->dir_y * speed;
	}

	if(player->key_left)
	{
		player-> x += player->dir_y * speed;
		player-> y -= player->dir_x * speed;
	}

	if(player->key_right)
	{
		player->x -= player->dir_y * speed;
		player->y += player->dir_x * speed;
	}

}

// nouveau x = x × cos(a) − y × sin(a)
// nouveau y = x × sin(a) + y × cos(a)

void player_movement(t_player *player)
{
	float speed = 0.03;
	float angle_speed = 0.03;

	float dir_x_tmp = player->dir_x;
	float dir_y_tmp = player->dir_y;

	float plane_x_tmp = player->plane_x;
	float plane_y_tmp = player->plane_y;

	if(player->left_rotation)
	{
		player->dir_x = dir_x_tmp * cos(-angle_speed) - dir_y_tmp * sin(-angle_speed);
		player->dir_y = dir_x_tmp * sin(-angle_speed) + dir_y_tmp * cos(-angle_speed);

		player->plane_x = plane_x_tmp * cos(-angle_speed) - plane_y_tmp * sin(-angle_speed);
		player->plane_y = plane_x_tmp * sin(-angle_speed) + plane_y_tmp * cos(-angle_speed);

	}

	if(player->right_rotation)
	{
		player->dir_x = dir_x_tmp * cos(angle_speed) - dir_y_tmp * sin(angle_speed);
		player->dir_y = dir_x_tmp * sin(angle_speed) + dir_y_tmp * cos(angle_speed);

		player->plane_x = plane_x_tmp * cos(angle_speed) - plane_y_tmp * sin(angle_speed);
		player->plane_y = plane_x_tmp * sin(angle_speed) + plane_y_tmp * cos(angle_speed);

	}

	player_walk(player, speed);
}
