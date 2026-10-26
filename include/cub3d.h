/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:40:59 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/26 16:32:57 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1280
# define HEIGHT 720

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

# define PI 3.14159265

# define BLOCK 1

# define NO 0
# define SO 1
# define WE 2
# define EA 3

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

typedef struct s_ray
{

	float dir_x;
	float dir_y;
	int map_x;
	int map_y;
	float delta_x;
	float delta_y;
	int step_x;
	int step_y;
	float side_dist_x;
	float side_dist_y;
	int side;
	float wall_dist;
}	t_ray;

typedef struct s_player
{
	float x;
	float y;

	float dir_x;
	float dir_y;
	float plane_x;
	float plane_y;

	bool key_up;
	bool key_down;
	bool key_left;
	bool key_right;
	bool left_rotation;
	bool right_rotation;

}	t_player;

typedef struct s_map
{
	char	*gnl_line;
	char	*line;
	char	**array;
	int		width;
	int		height;
	int		fd;
}	t_map;

typedef struct	s_texture
{
	int height;
	int width;
	char *buff;
	void *img;
	int bpp;
	int size_line;
	int endian;
}	t_texture;

typedef struct s_data
{
	int		floor_color;
	int		sky_color;
	char	*textures[4];
	t_texture img[4];
}	t_data;

typedef struct s_game
{
	void *mlx;
	void *win;
	void *image;
	char *addr;

	int bpp;
	int size_line;
	int endif;
	t_data	data;
	t_map	map;
	t_player player;
}	t_game;


void init_game(t_game *game);
void init_textures(t_game *game);
void init_player(t_player *player);
void init_ray(t_game *game, t_ray *ray, int i);

int key_press(int keycode, t_game *game);
int key_release(int keycode, t_game *game);

void perform_dda(t_game *game, t_ray *ray);

int draw_loop(t_game *game);
void draw_walls(t_game *game, t_ray ray, int i);
void draw_background(t_game *game);
void draw_map(t_game *game);
void draw_square(int x, int y, int size, int color, t_game *game);

void player_movement(t_game *game);

float get_distance(float x,  float y, float ray_x, float ray_y);
int close_prog(t_game *game);
void free_all(t_game *game);
void put_pixel(int x, int y, int color, t_game *game);

char **get_map(void);
void put_pixel(int x, int y, int color, t_game *game);
bool raycast(float px, float py, t_game *game);

// PARSING

int		correct_file(t_map *map, char *file);
int		error_check(t_game *game);
int		find_args(t_game *game, char *line);
int		parsing(int ac, char **av, t_game *game);
int		parse_map(t_game *game);
int		parse_textures(t_game *game, char *line, int tex);
int		parse_color(t_game *game, char *line, int tex);
int		player_plane(t_game *game, char c);
int		player_direction(t_game *game, char c);
int		parse_player(t_game *game, int pos_y, int pos_x);
int		check_around(t_game *game, int pos_y, int pos_x);
int		valid_char(char c);
int		map_check(t_game *game);



#endif
