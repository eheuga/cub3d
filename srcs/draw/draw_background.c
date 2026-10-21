#include "cub3d.h"


static void add_colors(t_game *game, int color, int y)
{
	int x = 0;

	while(x < WIDTH)
	{
		put_pixel(x, y, color, game);
		x++;
	}
}

void draw_background(t_game *game)
{
	int y = 0;

	while(y < HEIGHT)
	{
		if(y >= HEIGHT / 2)
			add_colors(game, game->data.floor_color, y);
		else
			add_colors(game, game->data.sky_color, y);
		y++;
	}
}
