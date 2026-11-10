#include "cub3d.h"

int	close_prog(t_game *game)
{
	mlx_destroy_image(game->mlx, game->image);
	free_all(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
