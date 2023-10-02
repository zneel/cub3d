/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:12:12 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/02 10:20:09 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include "lists.h"
#include "parsing.h"
#include <fcntl.h>

static t_bool	has_all_data(t_map *map, char *line)
{
	if (map->data.ceiling == -1 || map->data.floor == -1 || map->data.no == NULL
		|| map->data.ea == NULL || map->data.so == NULL || map->data.we == NULL
		|| !map->data.no_bool || !map->data.ea_bool || !map->data.so_bool
		|| !map->data.we_bool)
	{
		free(line);
		return (false);
	}
	return (true);
}

t_bool	lst_to_map(t_list *list, t_map *map)
{
	if (!alloc_map(list, map))
	{
		map->map = NULL;
		return (false);
	}
	if (!fill_map(list, map))
	{
		ft_dprintf(1, "Error\nInvalid map.\n");
		return (false);
	}
	return (true);
}

t_bool	parse_infos(char *line, t_map *map)
{
	if (parse_textures(line, map) || parse_ceiling_color(line, map)
		|| parse_floor_color(line, map))
	{
		free(line);
		return (true);
	}
	return (false);
}

t_bool	parse_data(int fd, t_map *map)
{
	char	*line;
	t_list	*list;

	list = NULL;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (parse_infos(line, map) || !has_all_data(map, line))
			continue ;
		if (!parse_map_list(&list, line))
		{
			get_next_line(-1);
			ft_dprintf(1, "Error\nInvalid map.\n");
			return (ft_lstclear(&list, free), close(fd), false);
		}
	}
	if (!lst_to_map(list, map))
		return (ft_lstclear(&list, free), close(fd), false);
	return (ft_lstclear(&list, free), close(fd), true);
}

t_bool	parse_cubfile(char *file, t_map *map)
{
	int	fd;

	check_file(file);
	fd = open(file, O_RDONLY, 0644);
	if (fd == -1)
		perror_and_exit(file);
	if (!parse_data(fd, map))
		return (destroy_map(map), false);
	if (!is_scene_valid(map))
		return (destroy_map(map), false);
	parse_player_start_pos(map);
	return (true);
}
