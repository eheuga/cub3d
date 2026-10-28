/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:31:42 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/27 12:06:47 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	player_plane(t_game *game, char c)
{
	if (c == 'N' || c == 'S')
	{
		game->player.plane_y = 0;
		if (c == 'S')
			game->player.plane_x = -0.66;
		else
			game->player.plane_x = 0.66;
		return (1);
	}
	else if (c == 'E' || c == 'W')
	{
		game->player.plane_x = 0;
		if (c == 'W')
			game->player.plane_y = -0.66;
		else
			game->player.plane_y = 0.66;
		return (1);
	}
	return (0);
}

static int	player_direction(t_game *game, char c)
{
	if (c == 'N' || c == 'S')
	{
		game->player.dir_x = 0;
		if (c == 'S')
			game->player.dir_y = 1;
		else
			game->player.dir_y = -1;
	}
	if (c == 'E' || c == 'W')
	{
		game->player.dir_y = 0;
		if (c == 'W')
			game->player.dir_x = -1;
		else
			game->player.dir_x = 1;
	}
	return (player_plane(game, c));
}

int	parse_player(t_game *game, int y, int x)
{
	if (player_direction(game, game->map.array[y][x]))
	{
		if (!check_around(game, y, x))
			return (error_message(ERR_MAP_OPEN, game->map.array[y]));
		game->player.x = x + 0.5;
		game->player.y = y + 0.5;
		game->map.array[y][x] = '0';
	}
	else
		return (0);
	return (1);
}
