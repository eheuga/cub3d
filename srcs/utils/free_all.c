/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:57:30 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/26 11:57:33 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_all(t_game *game)
{
	int i;

	i = 0;
	while(game->map.array && game->map.array[i])
	{
		free(game->map.array[i]);
		i++;
	}
	free(game->map.array);
	free(game->map.line);
	free(game->map.gnl_line);
	i = 0;
	while(i < 4)
	{
		free(game->data.textures[i]);
		if (game->data.img[i].img)
			mlx_destroy_image(game->mlx, game->data.img[i].img);
		i++;
	}
	free(game->mlx);
	return ;
}
