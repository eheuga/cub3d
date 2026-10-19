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
			add_colors(game, 0x3D2C2E, y);
		else
			add_colors(game, 0x1A1423, y);
		y++;
	}
}
