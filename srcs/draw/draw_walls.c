#include "cub3d.h"

static void draw_tex(t_game *game, t_texture tex , int i, int start_y, int end, float height, float wall_x)
{

	int tex_x = (int)(wall_x * tex.width);
	int tex_y;
	int index;
	int r;
	int g;
	int b;
	float step = tex.height / height;
	float text_pos = (start_y - HEIGHT / 2 + height / 2) * step;

	while(start_y < end)
	{
		tex_y = (int)text_pos % tex.height;
		if(tex_y < 0)
			tex_y += tex.height;
		text_pos += step;
		index = tex_y * tex.size_line + tex_x * tex.bpp / 8;
		r = (unsigned char)tex.buff[index + 2];
		g = (unsigned char)tex.buff[index + 1];
		b = (unsigned char)tex.buff[index];
		put_pixel(i, start_y, (r << 16) | (g << 8) | b, game);
		start_y++;
	}
}

void draw_walls(t_game *game, t_ray ray, int i)
{
	float height = HEIGHT / ray.wall_dist;
	int start_y = HEIGHT/ 2 - height / 2;
	int end = HEIGHT /2 + height / 2;
	float wall_x;

	if(start_y < 0)
		start_y = 0;
	if(end >= HEIGHT)
		end = HEIGHT - 1;

	if(ray.side == 1)
	{
		wall_x = game->player.x + ray.wall_dist * ray.dir_x;
		wall_x -= floor(wall_x);
		if(ray.step_y == 1)
			draw_tex(game, game->data.img[NO], i, start_y, end, height, wall_x);
		else
			draw_tex(game, game->data.img[SO], i, start_y, end, height, wall_x);
	}
	else
	{
		wall_x = game->player.y + ray.wall_dist * ray.dir_y;
		wall_x -= floor(wall_x);
		if(ray.step_x == 1)
			draw_tex(game, game->data.img[WE], i, start_y, end, height, wall_x);
		else
			draw_tex(game, game->data.img[EA], i, start_y, end, height, wall_x);
	}
}
