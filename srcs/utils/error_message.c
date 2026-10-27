/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonpouet <leonpouet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:56:47 by leonpouet         #+#    #+#             */
/*   Updated: 2026/10/26 12:40:49 by leonpouet        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	system_error(int error, char *file)
{
	int	err;

	err = errno;
	ft_putstr_fd("Error\n", 2);
	if (file)
		ft_putstr_fd(file, 2);
	else
		ft_putstr_fd("memory allocation failed", 2);
	ft_putstr_fd(strerror(err), 2);
	ft_putstr_fd("\n", 2);
}

void	arg_error(int error)
{
	ft_putstr_fd("Error\n", 2);
	if (error == ERR_ARGS)
		ft_putstr_fd("usage: ./cub3D <map.cub>\n", 2);
	else if (error == ERR_EXTENSION)
		ft_putstr_fd("map file must have a .cub extension\n", 2);
}

void	header_error(int error)
{
	ft_putstr_fd("Error\n", 2);
	if (error == ERR_UNKNOWN_ID)
		ft_putstr_fd("unknown identifier in file\n", 2);
	else if (error == ERR_DUP_TEXTURE)
		ft_putstr_fd("texture defined more than once\n", 2);
	else if (error == ERR_DUP_COLOR)
		ft_putstr_fd("color defined more than once\n", 2);
	else if (error == ERR_TEXTURE_PATH)
		ft_putstr_fd("invalid texture path\n", 2);
	else if (error == ERR_COLOR)
		ft_putstr_fd("invalid color, expected R,G,B between 0 and 255\n", 2);
	else if (error == ERR_MISSING_ELEM)
		ft_putstr_fd("missing texture or color before the map\n", 2);
}

void	map_error(int error)
{
	ft_putstr_fd("Error\n", 2);
	if (error == ERR_NO_MAP)
		ft_putstr_fd("no map found in file\n", 2);
	else if (error == ERR_EMPTY_LINE)
		ft_putstr_fd("empty line inside the map\n", 2);
	else if (error == ERR_INVALID_CHAR)
		ft_putstr_fd("invalid character in map\n", 2);
	else if (error == ERR_NO_PLAYER)
		ft_putstr_fd("no player start position\n", 2);
	else if (error == ERR_MANY_PLAYERS)
		ft_putstr_fd("more than one player start position\n", 2);
	else if (error == ERR_MAP_OPEN)
		ft_putstr_fd("map is not closed by walls\n", 2);
}

int	error_message(int error, char *file)
{
	if (error < 10)
		system_error(error, file);
	else if (error < 20)
		arg_error(error);
	else if (error < 30)
		header_error(error);
	else if (error < 40)
		map_error(error);
	return (0);
}
