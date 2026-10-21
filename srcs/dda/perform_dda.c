#include "cub3d.h"

void perform_dda(t_game *game, t_ray *ray)
{

	while(game->map.array[ray->map_y][ray->map_x] != '1')
	{
		if(ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
	}
	if(ray->side)
		ray->wall_dist = ray->side_dist_y - ray->delta_y;
	else
		ray->wall_dist = ray->side_dist_x - ray->delta_x;

}
