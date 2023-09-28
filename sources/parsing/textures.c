/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:42:23 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/28 11:57:07 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parsing.h"

static void	get_textures(char *line, t_orientation orientation,
		t_map_data *data)
{
	while (*line && ft_isspace(*line))
		line++;
	if (orientation == NORTH)
	{
		data->no = ft_strtrim(line, "\n ");
		data->no_bool = data->no != NULL;
	}
	else if (orientation == SOUTH)
	{
		data->so = ft_strtrim(line, "\n ");
		data->so_bool = data->so != NULL;
	}
	else if (orientation == EAST)
	{
		data->ea = ft_strtrim(line, "\n ");
		data->ea_bool = data->ea != NULL;
	}
	else if (orientation == WEST)
	{
		data->we = ft_strtrim(line, "\n ");
		data->we_bool = data->we != NULL;
	}
}

t_bool	parse_textures(char *line, t_map *map)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		if (map->data.no_bool)
			return (false);
		return (get_textures(line + 2, NORTH, &map->data), true);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (map->data.so_bool)
			return (false);
		return (get_textures(line + 2, SOUTH, &map->data), true);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		if (map->data.ea_bool)
			return (false);
		return (get_textures(line + 2, EAST, &map->data), true);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		if (map->data.we_bool)
			return (false);
		return (get_textures(line + 2, WEST, &map->data), true);
	}
	return (false);
}
