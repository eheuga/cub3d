#include "cub3d.h"

void init_textures(t_game *game)
{
	int i = 0;

	while(i < 4)
	{
		game->data.img[i].img  = mlx_xpm_file_to_image(game->mlx, game->data.textures[i], &game->data.img[i].width, &game->data.img[i].height);
		game->data.img[i].buff  = mlx_get_data_addr(game->data.img[i].img, &game->data.img[i].bpp, &game->data.img[i].size_line, &game->data.img[i].endian);
		i++;
	}

}
