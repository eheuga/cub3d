/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubau <ldubau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:27:35 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/19 16:26:28 by ldubau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		if (i == 0 || i == map->height - 1)
		{
			while (map->tab[i][j])
			{
				if (map->tab[i][j] != '1')
					map->tab[i][j] = '1';
				j++;
			}
		}
		else if (map->tab[i][0] != '1' ||
		map->tab[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	correct_file(t_map *map, char *file)
{
	char *tmp;

	tmp = ft_strnstr(file, ".cub", ft_strlen(file));
	if (!tmp || ft_strlen(tmp) < 4)
		return (0);
	if (ft_strlen(file) <= 4)
		return (0);
	map->fd = open();

}

int	error_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.tab[i])
	{
		j = 0;
		while (game->map.tab[i][j])
			j++;
		if (j != game->map.width)
			return (error_message(4));
		i++;
	}
	if (i != game->map.height)
		return (error_message(4));
	if (!check_wall(&game->map))
		return (error_message(6));
	return (1);
}

