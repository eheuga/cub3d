#include "cub3d.h"


float get_distance(float x,  float y, float ray_x, float ray_y)
{
	float delta_x = ray_x - x;
	float delta_y = ray_y - y;
	float dist = sqrt(delta_x * delta_x + delta_y * delta_y);

	return dist;
}


void init_fail(t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	if (game->image)
		mlx_destroy_image(game->mlx, game->image);
	free_all(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	return ;
}

int main(int ac, char **av)
{
	t_game game;

	ft_bzero(&game, sizeof(t_game));
	game.map.fd = -1;
	game.data.floor_color = -1;
	game.data.sky_color = -1;
	if (!parsing(ac, av, &game))
	{
		free_all(&game);
		return (1);
	}

	if (!init_game(&game))
	{
		init_fail(&game);
		return (1);
	}

	game.addr = mlx_get_data_addr(game.image, &game.bpp, &game.size_line, &game.endif);

	mlx_hook(game.win, 2, 1L<<0, key_press, &game);
	mlx_hook(game.win, 3, 1L<<1, key_release, &game);
	mlx_hook(game.win, 17, 0, close_prog, &game);

	mlx_loop_hook(game.mlx, draw_loop, &game);

	mlx_loop(game.mlx);

	return 0;
}
