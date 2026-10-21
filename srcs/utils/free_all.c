#include "cub3d.h"

void free_all(t_game *game)
{
	int i;

	i = 0;
	while(game->map.array && game->map.array[i])
	{
		free(game->map.array[i]);
		i++;
	}
	free(game->map.array);
	free(game->map.line);
	i = 0;
	while(i < 4)
	{
		free(game->data.textures[i]);
		i++;
	}
	free(game->mlx);
	return ;
}
