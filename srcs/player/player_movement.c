#include "cub3d.h"

#define PLAYER game->player

static int is_wall(t_game *game, float x, float y)
{
	if(game->map.array[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

static void player_walk(t_game *game, float speed)
{
	float new_x;
	float new_y;
	float marge = 0.1;


	if(PLAYER.key_up)
	{
		new_x = PLAYER.x + PLAYER.dir_x * (speed + marge);
		new_y = PLAYER.y + PLAYER.dir_y * (speed + marge);
		if(!is_wall(game,new_x, PLAYER.y ))
			PLAYER.x += PLAYER.dir_x * speed;
		if(!is_wall(game, PLAYER.x, new_y))
			PLAYER.y += PLAYER.dir_y * speed;
	}
	if(PLAYER.key_down)
	{
		new_x = PLAYER.x - PLAYER.dir_x * (speed + marge);
		new_y = PLAYER.y - PLAYER.dir_y * (speed + marge);
		if(!is_wall(game,new_x, PLAYER.y ))
			PLAYER.x -= PLAYER.dir_x * speed;
		if(!is_wall(game, PLAYER.x, new_y))
			PLAYER.y -= PLAYER.dir_y * speed;
	}
	if(PLAYER.key_left)
	{
		new_x = PLAYER.x + PLAYER.dir_y * (speed + marge);
		new_y = PLAYER.y - PLAYER.dir_x * (speed + marge);
		if(!is_wall(game,new_x, PLAYER.y ))
			PLAYER.x += PLAYER.dir_y * speed;
		if(!is_wall(game, PLAYER.x, new_y))
			PLAYER.y -= PLAYER.dir_x * speed;
	}
	if(PLAYER.key_right)
	{
		new_x = PLAYER.x - PLAYER.dir_y * (speed + marge);
		new_y = PLAYER.y + PLAYER.dir_x * (speed + marge);
		if(!is_wall(game, new_x, PLAYER.y))
			PLAYER.x -= PLAYER.dir_y * speed;
		if(!is_wall(game, PLAYER.x, new_y))
			PLAYER.y += PLAYER.dir_x * speed;
	}
}


void player_movement(t_game *game)
{
	float speed = 0.025;
	float angle_speed = 0.012;
	float dir_x_tmp = PLAYER.dir_x;
	float dir_y_tmp = PLAYER.dir_y;
	float plane_x_tmp = PLAYER.plane_x;
	float plane_y_tmp = PLAYER.plane_y;

	if(PLAYER.left_rotation)
	{
		PLAYER.dir_x = dir_x_tmp * cos(-angle_speed) - dir_y_tmp * sin(-angle_speed);
		PLAYER.dir_y = dir_x_tmp * sin(-angle_speed) + dir_y_tmp * cos(-angle_speed);
		PLAYER.plane_x = plane_x_tmp * cos(-angle_speed) - plane_y_tmp * sin(-angle_speed);
		PLAYER.plane_y = plane_x_tmp * sin(-angle_speed) + plane_y_tmp * cos(-angle_speed);
	}
	if(PLAYER.right_rotation)
	{
		PLAYER.dir_x = dir_x_tmp * cos(angle_speed) - dir_y_tmp * sin(angle_speed);
		PLAYER.dir_y = dir_x_tmp * sin(angle_speed) + dir_y_tmp * cos(angle_speed);
		PLAYER.plane_x = plane_x_tmp * cos(angle_speed) - plane_y_tmp * sin(angle_speed);
		PLAYER.plane_y = plane_x_tmp * sin(angle_speed) + plane_y_tmp * cos(angle_speed);
	}
	player_walk(game, speed);
}
