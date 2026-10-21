#include "cub3d.h"

void draw_map(t_game *game)
{
	char **map = game->map.array;
	int color = 0x0000FF;
	int y = 0;
	int x;

	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(map[y][x] == '1')
				draw_square(x * BLOCK, y * BLOCK,BLOCK, color, game);
			x++;
		}
		y++;
	}

}
