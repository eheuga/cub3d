#include "cub3d.h"

int draw_loop(t_game *game)
{
	t_player *player = &game->player;
	t_ray ray;

	player_movement(player);
	draw_background(game);
	// draw_square(player->x, player->y, 5, 0x00ffff, game);
	// draw_map(game);


	int i  = 0;

	while(i < WIDTH)
	{
		init_ray(game, &ray, i);
		perform_dda(game, &ray);
		draw_walls(game, ray, i);
		i++;
	}

	mlx_put_image_to_window(game->mlx, game->win, game->image, 0, 0);
	return 0;
}
