/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:07:50 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/28 13:31:45 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

t_vec2	spawn_dir(t_map *map, int x, int y)
{
	if (map->map[y][x] == PN)
		return ((t_vec2){0, 1});
	else if (map->map[y][x] == PS)
		return ((t_vec2){0, -1});
	else if (map->map[y][x] == PE)
		return ((t_vec2){1, 0});
	else if (map->map[y][x] == PW)
		return ((t_vec2){-1, 0});
	else
		return ((t_vec2){0, 0});
}

static t_bool	is_player(t_map_value val)
{
	if (val == PN || val == PS || val == PE || val == PW)
		return (true);
	return (false);
}

void	parse_player_start_pos(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y_max)
	{
		x = 0;
		while (x < map->x_max)
		{
			if (is_player(map->map[y][x]))
			{
				map->data.spawn.dir = spawn_dir(map, x, y);
				map->data.spawn.x = x;
				map->data.spawn.y = y;
			}
			x++;
		}
		y++;
	}
}
