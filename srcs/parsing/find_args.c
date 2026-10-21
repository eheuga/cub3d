/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:45:04 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/21 16:49:58 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	return (0);
}
