/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:15:12 by leonpouet         #+#    #+#             */
/*   Updated: 2026/11/06 12:42:57 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parsing(int ac, char **av, t_game *game)
{
	int check;

	if (ac != 2 || av[1][0] == '\0')
		return (0);
	check = correct_file(&game->map, av[1]);
	if (!check)
		return (0);
	check = parse_map(game);
	close(game->map.fd);
	game->map.fd = -1;
	if(!check)
			return (0);
	check = map_check(game);
	if (!check)
		return (0);
	return (1);
}
