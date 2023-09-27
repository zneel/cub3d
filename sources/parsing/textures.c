/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:42:23 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/27 19:55:48 by ebouvier         ###   ########.fr       */
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
		data->no = ft_strtrim(line, "\n ");
	else if (orientation == SOUTH)
		data->so = ft_strtrim(line, "\n ");
	else if (orientation == EAST)
		data->ea = ft_strtrim(line, "\n ");
	else if (orientation == WEST)
		data->we = ft_strtrim(line, "\n ");
}

t_bool	parse_textures(char *line, t_map *map)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		get_textures(line + 2, NORTH, &map->data);
		return (true);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		get_textures(line + 2, SOUTH, &map->data);
		return (true);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		get_textures(line + 2, EAST, &map->data);
		return (true);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		get_textures(line + 2, WEST, &map->data);
		return (true);
	}
	else
		return (false);
}
