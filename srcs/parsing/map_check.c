/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 19:49:51 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/22 12:08:41 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_around(t_game *game, int pos_y, int pos_x)
{
	char	**map;

	map = game->map.array;
	if (pos_y == 0 || pos_x == 0)
		return (0);
	if (pos_y == game->map.height - 1 || pos_x == game->map.width - 1)
		return (0);
	if (map[pos_y - 1][pos_x] == ' ' || map[pos_y + 1][pos_x] == ' ')
		return (0);
	if (map[pos_y][pos_x - 1] == ' ' || map[pos_y][pos_x + 1] == ' ')
		return (0);
	return (1);
}

int	valid_char(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	map_check(t_game *game)
{
	int	i;
	int	j;
	int	play;
	int	ret;

	i = 0;
	play = 0;
	while (game->map.array[i])
	{
		j = 0;
		while (game->map.array[i][j])
		{
			ret = parse_player(game, i, j);
			if (ret == -1 || !valid_char(game->map.array[i][j]))
				return (0); // player uncomplete or wrong char
			play += ret;
			if (game->map.array[i][j] == '0' && !check_around(game, i, j))
				return (0); // map uncomplete
			j++;
		}
		i++;
	}
	if (play != 1)
		return (0); // wrong number of player
	return (1);
}
