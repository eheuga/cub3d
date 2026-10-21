/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:27:35 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/20 13:36:47 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	correct_file(t_map *map, char *file)
{
	char *tmp;

	tmp = ft_strnstr(file, ".cub", ft_strlen(file));
	if (!tmp || ft_strlen(tmp) < 4)
		return (0);
	if (ft_strlen(file) <= 4)
		return (0);
	map->fd = open(file, O_RDONLY);
	if (map->fd < 0)
		return (0);

}

int	error_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;

	return (1);
}

