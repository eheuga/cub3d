/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 19:49:51 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/27 14:40:31 by leonpouet        ###   ########.fr       */
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

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	valid_char(char c)
{
	if (c == '0' || c == '1' || c == ' ')
		return (1);
	if (is_player(c))
		return (1);
	return (0);
}

int	map_check_loop(t_game *game, int *play)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.array[i])
	{
		j = 0;
		while (game->map.array[i][j])
		{
			if (is_player(game->map.array[i][j]))
			{
				if (!parse_player(game, i, j))
					return (0);
				*play += 1;
			}
			if (!valid_char(game->map.array[i][j]))
				return (error_message(ERR_INVALID_CHAR, game->map.array[i]));
			if (game->map.array[i][j] == '0' && !check_around(game, i, j))
				return (error_message(ERR_MAP_OPEN, game->map.array[i]));
			j++;
		}
		i++;
	}
	return (1);
}

int	map_check(t_game *game)
{
	int	play;

	play = 0;
	if (!map_check_loop(game, &play))
		return (0);
	if (play == 0)
		return (error_message(ERR_NO_PLAYER, NULL));
	if (play > 1)
		return (error_message(ERR_MANY_PLAYERS, NULL));
	return (1);
}
