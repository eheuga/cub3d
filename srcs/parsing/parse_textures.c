/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:48:05 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/21 16:50:06 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
