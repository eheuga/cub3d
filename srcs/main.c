#include "cub3d.h"


float get_distance(float x,  float y, float ray_x, float ray_y)
{
	float delta_x = ray_x - x;
	float delta_y = ray_y - y;
	float dist = sqrt(delta_x * delta_x + delta_y * delta_y);

	return dist;
}





bool raycast(float px, float py, t_game *game)
{
	int x = px;
	int y = py;
	if(game->map.array[y][x] == '1')
		return true;
	return false;

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
		ft_putstr_fd("Error\n", 2);
		if (game.map.fd >= 0)
			close(game.map.fd);
		free_all(&game);
		return (1);
	}
	init_game(&game);

	game.addr = mlx_get_data_addr(game.image, &game.bpp, &game.size_line, &game.endif);

	mlx_hook(game.win, 2, 1L<<0, key_press, &game);
	mlx_hook(game.win, 3, 1L<<1, key_release, &game);
	mlx_hook(game.win, 17, 0, close_prog, &game);

	mlx_loop_hook(game.mlx, draw_loop, &game);

	mlx_loop(game.mlx);

	return 0;
}
