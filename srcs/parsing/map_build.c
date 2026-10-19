/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:11:02 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/13 11:25:35 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	map_buid(int fd, t_map *map)
{
	char	*tmp;
	char	*readed_line;

	tmp = NULL;
	readed_line = get_next_line(fd);
	if (!readed_line)
		return ;
	map->width = ft_strlen(readed_line) - 1;
	map->height = 0;
	map->line = ft_strdup("");
	while (readed_line)
	{
		tmp = ft_strjoin(map->line, readed_line);
		if (!tmp)
			return ;
		free(map->line);
		free(readed_line);
		map->line = tmp;
		readed_line = get_next_line(fd);
		map->height++;
	}
	map->array = ft_split(map->line, '\n');
	parse_object(map);
}
