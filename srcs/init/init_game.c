#include "cub3d.h"

void init_game(t_game *game)
{
	init_player(&game->player);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "CUB3D");
	game->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	init_textures(game);
}
