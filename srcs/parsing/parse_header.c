/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:45:04 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/28 12:38:41 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_id(char *line, char *id)
{
	int	len;

	len = ft_strlen(id);
	if (ft_strncmp(line, id, len) != 0)
		return (0);
	if (line[len] == ' ' || line[len] == '\t')
		return (1);
	return (0);
}

int	find_args(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (is_id(line + i, "NO"))
		return (parse_textures(game, line + i, NO));
	else if (is_id(line + i, "SO"))
		return (parse_textures(game, line + i, SO));
	else if (is_id(line + i, "WE"))
		return (parse_textures(game, line + i, WE));
	else if (is_id(line + i, "EA"))
		return (parse_textures(game, line + i, EA));
	else if (is_id(line + i, "F"))
		return (parse_color(game, line + i, 'F'));
	else if (is_id(line + i, "C"))
		return (parse_color(game, line + i, 'C'));
	else if (line[i] == '1' || line[i] == '0')
		return (error_message(ERR_MISSING_ELEM, NULL));
	else if (!is_blank_line(line))
		return (error_message(ERR_UNKNOWN_ID, line));
	return (-1);
}

int	parse_arg_loop(t_game *game, int fd)
{
	int	check;
	int	count;

	count = 0;
	game->map.line = ft_strdup("");
	if (!game->map.line)
		return (error_message(ERR_MALLOC, NULL));
	while (game->map.gnl_line && count != 6)
	{
		check = find_args(game, game->map.gnl_line);
		if (check == 0)
			return (0);
		else if (check == 1)
			count += 1;
		free(game->map.gnl_line);
		game->map.gnl_line = get_next_line(fd);
	}
	if (count < 6)
		return (error_message(ERR_MISSING_ELEM, NULL));
	return (1);
}
