/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:34:37 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/28 12:35:30 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_file(t_game *game)
{
	char	*tmp;

	tmp = NULL;
	game->map.gnl_line = get_next_line(game->map.fd);
	if (!game->map.gnl_line)
		return (error_message(ERR_NO_MAP, NULL));
	if (!parse_arg_loop(game, game->map.fd))
		return (0);
	if (!parse_map_loop(game, game->map.fd))
		return (0);
	tmp = ft_strtrim(game->map.line, "\n");
	if (!tmp)
		return (error_message(ERR_MALLOC, NULL));
	free(game->map.line);
	game->map.line = tmp;
	if (game->map.line[0] == '\0')
		return (error_message(ERR_NO_MAP, NULL));
	if (!check_line(game, game->map.line))
		return (0);
	game->map.height = adjust_array(game);
	if (!game->map.height)
		return (0);
	return (1);
}
