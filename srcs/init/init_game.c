#include "cub3d.h"

int init_game(t_game *game)
{
	int ret;

	init_player(&game->player);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "CUB3D");
	if (!game->win)
		return (0);
	game->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->image)
		return (0);
	ret = init_textures(game);
	return (ret);
}
