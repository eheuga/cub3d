/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:15:12 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/20 13:48:10 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parsing(int ac, char **av, t_game *game)
{
	int check;

	if (ac != 2 || av[1][0] == '\0')
		return (0);
	check = correct_file(av[1]);
	if (!check)
		return (0);
	check = error_check(game);
	if (!check)
		return (0);
	check = error_check(game);
	if (!check)
		return (0);
}
