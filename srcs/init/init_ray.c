#include "cub3d.h"
#include <stdio.h>

void init_ray(t_game *game, t_ray *ray, int i)
{
	float column = 2 * (float)i / WIDTH - 1;

	ray->dir_x = game->player.dir_x + game->player.plane_x *  column;
	ray->dir_y = game->player.dir_y + game->player.plane_y *  column;
	ray->map_x = game->player.x;
	ray->map_y = game->player.y;
	ray->delta_x = fabs(1/ray->dir_x);
	ray->delta_y = fabs(1/ray->dir_y);

	if(ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player.x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1 -game->player.x) * ray->delta_x;
	}

	if(ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player.y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1 -game->player.y) * ray->delta_y;
	}



}
