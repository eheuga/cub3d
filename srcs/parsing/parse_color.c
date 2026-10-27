/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:49:04 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/27 15:51:35 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	color_loop(char *line, int *rgb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ',' && i > 0 && ft_isdigit(line[i - 1]) && j < 2)
			j++;
		else if (ft_isdigit(line[i]))
			rgb[j] = rgb[j] * 10 + (line[i] - '0');
		else if (line[i] == ',')
			return (error_message(ERR_COLOR, line));
		else
			return (error_message(ERR_COLOR_CHAR, line));
		if (rgb[j] > 255)
			return (error_message(ERR_COLOR_RANGE, line));
		i++;
	}
	if (j == 2 && ft_isdigit(line[i - 1]))
		return (1);
	return (error_message(ERR_COLOR, line));
}

int	parse_color(t_game *game, char *line, int tex)
{
	int		rgb[3];
	char	*str;
	int		check;

	str = ft_strtrim(line + 1, " \t\n");
	if (!str)
		return (error_message(ERR_MALLOC, NULL));
	ft_bzero(rgb, sizeof(int) * 3);
	check = color_loop(str, rgb);
	free(str);
	if (!check)
		return (0);
	if (tex == 'C' && game->data.sky_color == -1)
		game->data.sky_color = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	else if (tex == 'F' && game->data.floor_color == -1)
		game->data.floor_color = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	else
		return (error_message(ERR_DUP_COLOR, line));
	return (1);
}
