/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 09:11:02 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/21 20:08:21 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_line(t_game *game, char *line)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			if (j > max)
				max = j;
			if (line[i + 1] == '\n')
				return (error_message(ERR_EMPTY_LINE, NULL));
			j = 0;
		}
		else
			j++;
		i++;
	}
	if (j > max)
		max = j;
	game->map.width = max;
	return (1);
}

int	adjust_array(t_game *game)
{
	char	*newline;
	int		i;

	i = 0;
	game->map.array = ft_split(game->map.line, '\n');
	if (!game->map.array)
		return (error_message(ERR_MALLOC, NULL));
	while (game->map.array[i])
	{
		newline = malloc (sizeof(char) * (game->map.width + 1));
		if (!newline)
			return (error_message(ERR_MALLOC, NULL));
		ft_memset(newline, ' ', game->map.width);
		ft_memcpy(newline, game->map.array[i],
			ft_strlen(game->map.array[i]));
		newline[game->map.width] = '\0';
		free(game->map.array[i]);
		game->map.array[i] = newline;
		i++;
	}
	return (i);
}

int	parse_loop(t_game *game, int fd)
{
	char	*tmp;
	int		count;

	tmp = NULL;
	count = 0;
	game->map.line = ft_strdup("");
	if (!game->map.line)
		return (error_message(ERR_MALLOC, NULL));
	while (game->map.gnl_line)
	{
		if (count < 6)
			count += find_args(game, game->map.gnl_line);
		else if (count == 6)
		{
			tmp = ft_strjoin(game->map.line, game->map.gnl_line);
			if (!tmp)
				return (error_message(ERR_MALLOC, NULL));
			free(game->map.line);
			game->map.line = tmp;
		}
		free(game->map.gnl_line);
		game->map.gnl_line = get_next_line(fd);
	}
	return (1);
}

int	parse_map(t_game *game)
{
	char	*tmp;

	tmp = NULL;
	game->map.gnl_line = get_next_line(game->map.fd);
	if (!game->map.gnl_line)
		return (0);
	if (!parse_loop(game, game->map.fd))
		return (0);
	tmp = ft_strtrim(game->map.line, "\n");
	if (!tmp)
		return (error_message(ERR_MALLOC, NULL));
	free(game->map.line);
	game->map.line = tmp;
	if (!check_line(game, game->map.line))
		return (0);
	game->map.height = adjust_array(game);
	if (!game->map.height)
		return (0);
	return (1);
}
