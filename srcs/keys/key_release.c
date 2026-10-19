#include "cub3d.h"

int key_release(int keycode, t_game *game)
{
	if(keycode == W)
		game->player.key_up = false;
	if(keycode == S)
		game->player.key_down = false;
	if(keycode == A)
		game->player.key_left = false;
	if(keycode == D)
		game->player.key_right = false;
	if(keycode == LEFT)
		game->player.left_rotation = false;
	if(keycode == RIGHT)
		game->player.right_rotation = false;
	return 0;
}
