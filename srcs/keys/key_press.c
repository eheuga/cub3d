#include "cub3d.h"

int key_press(int keycode, t_game *game)
{
	if(keycode == W)
		game->player.key_up = true;
	if(keycode == S)
		game->player.key_down = true;
	if(keycode == A)
		game->player.key_left = true;
	if(keycode == D)
		game->player.key_right = true;
	if(keycode == LEFT)
		game->player.left_rotation = true;
	if(keycode == RIGHT)
		game->player.right_rotation = true;
	if(keycode == ESC)
		close_prog(game);
	return 0;
}

