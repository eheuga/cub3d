#include "cub3d.h"

void draw_walls(t_game *game, t_ray ray, int i)
{
	float height = HEIGHT / ray.wall_dist;
	int start_y = HEIGHT/ 2 - height / 2;
	int end = HEIGHT /2 + height / 2;

	if(start_y < 0)
		start_y = 0;
	if(end >= HEIGHT)
		end = HEIGHT - 1;

	while(start_y < end)
	{
		if(ray.side == 1)
			put_pixel(i, start_y, 0x5A4A3D, game);
		else
			put_pixel(i, start_y, 0x6B5B4E, game);
		start_y++;
	}
}
