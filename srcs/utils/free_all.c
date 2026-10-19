#include "cub3d.h"

void free_all(t_game *game)
{
	free(game->mlx);
	free(game->map);
	return ;
}
