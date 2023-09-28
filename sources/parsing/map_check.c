/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:47:27 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/28 11:02:21 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "parsing.h"

static t_bool	is_player(t_map_value val)
{
	if (val == PN)
		return (true);
	else if (val == PS)
		return (true);
	else if (val == PE)
		return (true);
	else if (val == PW)
		return (true);
	return (false);
}

static t_bool	check_player(t_map *map, int x, int y)
{
	if (is_player(map->map[y][x]))
	{
		if (x == 0 || y == 0 || x == map->x_max - 1 || y == map->y_max - 1)
			return (false);
		if (y - 1 >= 0 && map->map[y - 1][x] == SPACE)
			return (false);
		if (y + 1 < map->y_max && map->map[y + 1][x] == SPACE)
			return (false);
		if (x - 1 >= 0 && map->map[y][x - 1] == SPACE)
			return (false);
		if (x + 1 < map->x_max && map->map[y][x + 1] == SPACE)
			return (false);
	}
	return (true);
}

static t_bool	is_valid(t_map *map, int x, int y)
{
	if (map->map[y][x] == EMPTY)
	{
		if (x == 0 || y == 0 || x == map->x_max - 1 || y == map->y_max - 1)
			return (false);
		if (y - 1 >= 0 && map->map[y - 1][x] == SPACE)
			return (false);
		if (y + 1 < map->y_max && map->map[y + 1][x] == SPACE)
			return (false);
		if (x - 1 >= 0 && map->map[y][x - 1] == SPACE)
			return (false);
		if (x + 1 < map->x_max && map->map[y][x + 1] == SPACE)
			return (false);
	}
	return (true);
}

t_bool	check_closed_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y_max)
	{
		x = 0;
		while (x < map->x_max)
		{
			if (!is_valid(map, x, y) || !check_player(map, x, y))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
