/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:40:57 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/28 12:41:13 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	correct_file(t_map *map, char *file)
{
	char	*tmp;
	char	c;

	tmp = ft_strnstr(file + ft_strlen(file) - 4, ".cub", 4);
	if (!tmp || ft_strlen(tmp) != 4)
		return (error_message(ERR_EXTENSION, NULL));
	if (ft_strlen(file) <= 4)
		return (error_message(ERR_EXTENSION, NULL));
	map->fd = open(file, O_RDONLY);
	if (map->fd < 0)
		return (error_message(ERR_OPEN, file));
	if (read(map->fd, &c, 0) < 0)
		return (error_message(ERR_READ, file));
	return (1);
}
