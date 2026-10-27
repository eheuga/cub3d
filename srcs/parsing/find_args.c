/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:45:04 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/26 11:45:16 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	unknow_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' || !(line[i] >= 9 && line[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

int	find_args(t_game *game, char *line)
{
	if (ft_strnstr(line, "NO ", 3))
		return (parse_textures(game, line, NO));
	else if (ft_strnstr(line, "SO ", 3))
		return (parse_textures(game, line, SO));
	else if (ft_strnstr(line, "WE ", 3))
		return (parse_textures(game, line, WE));
	else if (ft_strnstr(line, "EA ", 3))
		return (parse_textures(game, line, EA));
	else if (ft_strnstr(line, "F ", 2))
		return (parse_color(game, line, 'F'));
	else if (ft_strnstr(line, "C ", 2))
		return (parse_color(game, line, 'C'));
	else if (!unknow_line(line))
		return (-1);
	return (0);
}
