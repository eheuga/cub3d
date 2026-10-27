/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:49:04 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/26 10:53:26 by leonpouet        ###   ########.fr       */
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
		else
			return (0); // error wrong color tuped
		if (rgb[j] > 255)
			return (0); // error wrong color typed
		i++;
	}
	if (j == 2 && ft_isdigit(line[i - 1]))
		return (1);
	return (0);
}

int	parse_color(t_game *game, char *line, int tex)
{
	int		rgb[3];
	char	*str;
	int		check;

	str = ft_strtrim(line + 1, " \n");
	if (!str)
		return (-1); // error malloc
	ft_bzero(rgb, sizeof(int) * 3);
	check = color_loop(str, rgb);
	free(str);
	if (!check)
		return (-1); // error wrong color typed
	if (tex == 'C' && game->data.sky_color == -1)
		game->data.sky_color = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	else if (tex == 'F' && game->data.floor_color == -1)
		game->data.floor_color = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	else
		return (-1); // double color argument
	return (1);
}
