/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:42:23 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/26 14:52:00 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parsing.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

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

t_bool	parse_ceiling_color(char *line, t_map *map)
{
	char	**colors;

	if (line[0] == 'C')
	{
		colors = ft_split(line + 1, ", ");
		if (!colors || !colors[0] || !colors[1] || !colors[2]
			|| split_len(colors) > 3)
		{
			ft_dprintf(2, "Error\nWrong color data.\n");
			return (free_split(colors), false);
		}
		map->data.ceiling = parse_color(colors[0], colors[1], colors[2]);
		free_split(colors);
		return (true);
	}
	return (false);
}

t_bool	parse_floor_color(char *line, t_map *map)
{
	char	**colors;

	if (line[0] == 'F')
	{
		colors = ft_split(line + 1, ", ");
		if (!colors || !colors[0] || !colors[1] || !colors[2]
			|| split_len(colors) > 3)
		{
			ft_dprintf(2, "Error\nWrong color data.\n");
			return (free_split(colors), false);
		}
		map->data.floor = parse_color(colors[0], colors[1], colors[2]);
		free_split(colors);
		return (true);
	}
	return (false);
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
