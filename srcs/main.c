#include "cub3d.h"


float get_distance(float x,  float y, float ray_x, float ray_y)
{
	float delta_x = ray_x - x;
	float delta_y = ray_y - y;
	float dist = sqrt(delta_x * delta_x + delta_y * delta_y);

	return dist;
}


void put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

char **get_map(void)
{
	char **map = malloc(sizeof(char *) * 12);

	map[0] = "111111111111111111111";
	map[1] = "10000000001000100001";
	map[2] = "10000000001000000001";
	map[3] = "10000100000000100001";
	map[4] = "10000000000000000001";
	map[5] = "10000000000000000001";
	map[6] = "10001100000000000001";
	map[7] = "10000000100000100001";
	map[8] = "10000000000000000001";
	map[9] = "10000000000000000001";
	map[10] = "11111111111111111111";
	map[11] = NULL;
	return map;

}



bool raycast(float px, float py, t_game *game)
{
	int x = px;
	int y = py;
	if(game->map[y][x] == '1')
		return true;
	return false;

}


int main()
{
	t_game game;

	ft_bzero(&game, sizeof(t_game));
	game.map.fd = -1;
	game.data.floor_color = -1;
	game.data.sky_color = -1;
	init_game(&game);

	game.data =  mlx_get_data_addr(game.image, &game.bpp, &game.size_line, &game.endif);

	mlx_hook(game.win, 2, 1L<<0, key_press, &game);
	mlx_hook(game.win, 3, 1L<<1, key_release, &game);
	mlx_hook(game.win, 17, 0, close_prog, &game);

	mlx_loop_hook(game.mlx, draw_loop, &game);

	mlx_loop(game.mlx);

	return 0;
}
