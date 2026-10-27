/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 16:48:05 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/27 15:51:20 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	parse_textures(t_game *game, char *line, int tex)
{
	if (game->data.textures[tex] != NULL)
		return (error_message(ERR_DUP_TEXTURE, line));
	game->data.textures[tex] = ft_strtrim(line + 2, " \t\n");
	if (!game->data.textures[tex])
		return (error_message(ERR_MALLOC, NULL));
	if (ft_strchr(game->data.textures[tex], ' ')
		|| game->data.textures[tex][0] == '\0')
		return (error_message(ERR_TEXTURE_PATH, line));
	return (1);
}
