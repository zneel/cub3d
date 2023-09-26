/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:48:35 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/26 17:26:42 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parsing.h"
#include <fcntl.h>

t_bool	check_texture_file(char *file)
{
	int	fd;

	if (!file)
		return (false);
	fd = open(file, O_RDWR, 0644);
	if (fd == -1)
	{
		ft_dprintf(2, "Error\nCannot open texture: %s.\n", file);
		return (false);
	}
	close(fd);
	return (true);
}

t_bool	check_paths(t_map *map)
{
	if (!check_texture_file(map->data.ea))
		return (false);
	else if (!check_texture_file(map->data.no))
		return (false);
	else if (!check_texture_file(map->data.so))
		return (false);
	else if (!check_texture_file(map->data.we))
		return (false);
	else
		return (true);
}

t_bool	is_data_valid(t_map *map)
{
	if (map->data.ceiling == -1 || map->data.floor == -1 || map->data.no == NULL
		|| map->data.ea == NULL || map->data.so == NULL || map->data.we == NULL)
	{
		ft_dprintf(2, "Error\nInvalid scene data.\n");
		return (false);
	}
	if (!check_paths(map))
		return (false);
	return (true);
}

t_bool	is_scene_valid(t_map *map)
{
	int		x;
	int		y;
	t_bool	ok;

	x = 0;
	y = 0;
	ok = true;
	while (y < map->y_max)
	{
		x = 0;
		while (x < map->x_max)
		{
			if (map->map[y][x] == ERR)
				ok = false;
			x++;
		}
		y++;
	}
	if (!is_data_valid(map))
		ok = false;
	return (ok);
}
