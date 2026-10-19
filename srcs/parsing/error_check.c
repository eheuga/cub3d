/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:27:35 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/19 14:29:52 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->array[i])
	{
		j = 0;
		if (i == 0 || i == map->height - 1)
		{
			while (map->array[i][j])
			{
				if (map->array[i][j] != '1')
					map->array[i][j] = '1';
				j++;
			}
		}
		else if (map->array[i][0] != '1' ||
		map->array[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	correct_file(char *file)
{
	if (ft_strnstr(file, ".cub\0", ft_strlen(av[1])))

}

int	error_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->array[i])
	{
		j = 0;
		while (game->map->array[i][j])
			j++;
		if (j != game->map->width)
			return (error_message(4));
		i++;
	}
	if (i != game->map->height)
		return (error_message(4));
	if (!check_wall(&game->map))
		return (error_message(6));
	return (1);
}

