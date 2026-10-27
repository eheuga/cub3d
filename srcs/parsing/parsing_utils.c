/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 11:27:35 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/26 11:25:46 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	correct_file(t_map *map, char *file)
{
	char *tmp;

	tmp = ft_strnstr(file, ".cub", ft_strlen(file));
	if (!tmp || ft_strlen(tmp) != 4)
		return (error_message(ERR_EXTENSION, NULL));
	if (ft_strlen(file) <= 4)
		return (error_message(ERR_EXTENSION, NULL));
	map->fd = open(file, O_RDONLY);
	if (map->fd < 0)
		return (error_message(ERR_OPEN, file));
	return (1);
}
