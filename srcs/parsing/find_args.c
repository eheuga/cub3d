/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:45:04 by leonpouet         #+#    #+#             */
/*   Updated: 2026/11/06 13:32:12 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_blank_line(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\n' && *line != '\t')
			return (0);
		line++;
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
	else if (is_blank_line(line))
		return (0);
	return (-1);
}
