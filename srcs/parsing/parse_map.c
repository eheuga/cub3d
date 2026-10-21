/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:11:02 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/21 13:56:52 by leonpouet        ###   ########.fr       */
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
	if (tex == 'C')
		game->data.sky_color = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	else if (tex == 'F')
		game->data.floor_color = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	return (1);
}

int	parse_textures(t_game *game, char *line, int tex)
{
	if (game->data.textures[tex] != NULL)
		return (-1); // error doublon
	game->data.textures[tex] = ft_strtrim(line + 2, " \n");
	if (!game->data.textures[tex])
		return (-1); // error malloc
	if (ft_strchr(game->data.textures[tex], ' '))
		return (-1); // error too many args
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
	return (0);
}

void	parse_map(int fd, t_game *game)
{
	char	*tmp;
	char	*readed_line;

	tmp = NULL;
	readed_line = get_next_line(fd);
	if (!readed_line)
		return ;
	game->map.line = readed_line;
	while (readed_line)
	{
		find_args(game, readed_line);
		free(readed_line);
		readed_line = get_next_line(fd);
	}
}


void	parse_map(int fd, t_map *map)
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
	map->tab = ft_split(map->line, '\n');
}
