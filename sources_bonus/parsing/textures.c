/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:42:23 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/03 10:47:05 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "parsing.h"

static void	get_textures(char *line, t_orientation orientation,
		t_map_data *data)
{
	while (*line && ft_isspace(*line))
		line++;
	if (orientation == NORTH)
		data->no = ft_strtrim(line, "\n ");
	else if (orientation == SOUTH)
		data->so = ft_strtrim(line, "\n ");
	else if (orientation == EAST)
		data->ea = ft_strtrim(line, "\n ");
	else if (orientation == WEST)
		data->we = ft_strtrim(line, "\n ");
}

static t_bool	parse_no(char *line, t_map *map)
{
	map->data.no_bool++;
	if (map->data.no_bool > 1)
		return (false);
	return (get_textures(line + 2, NORTH, &map->data), true);
}

static t_bool	parse_so(char *line, t_map *map)
{
	map->data.so_bool++;
	if (map->data.so_bool > 1)
		return (false);
	return (get_textures(line + 2, SOUTH, &map->data), true);
}

t_bool	parse_textures(char *line, t_map *map)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (parse_no(line, map));
	else if (line[0] == 'S' && line[1] == 'O')
		return (parse_so(line, map));
	else if (line[0] == 'E' && line[1] == 'A')
	{
		map->data.ea_bool++;
		if (map->data.ea_bool > 1)
			return (false);
		return (get_textures(line + 2, EAST, &map->data), true);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		map->data.we_bool++;
		if (map->data.we_bool > 1)
			return (false);
		return (get_textures(line + 2, WEST, &map->data), true);
	}
	return (false);
}
