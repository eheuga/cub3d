/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:15:12 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/28 12:35:17 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing(int ac, char **av, t_game *game)
{
	int	check;

	if (ac != 2 || av[1][0] == '\0')
		return (error_message(ERR_ARGS, NULL));
	check = correct_file(&game->map, av[1]);
	if (!check)
		return (0);
	check = read_file(game);
	if (!check)
		return (0);
	close(game->map.fd);
	game->map.fd = -1;
	check = map_check(game);
	if (!check)
		return (0);
	return (1);
}
