/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:43:00 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/29 14:25:46 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "lists.h"
#include "parsing.h"

t_map_value	map_content_to_map_value(char content)
{
	if (content == '0')
		return (EMPTY);
	else if (ft_isspace(content))
		return (SPACE);
	else if (content == '1')
		return (WALL);
	else if (content == 'N')
		return (PN);
	else if (content == 'S')
		return (PS);
	else if (content == 'E')
		return (PE);
	else if (content == 'W')
		return (PW);
	else
		return (ERR);
}

t_bool	alloc_map(t_list *list, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	map->x_max = get_x_max(list);
	map->y_max = ft_lstsize(list);
	map->map = malloc(sizeof(t_map_value *) * ft_lstsize(list));
	if (!map->map)
		return (false);
	while (y < map->y_max)
	{
		map->map[y] = malloc(sizeof(t_map_value) * map->x_max);
		if (!map->map[y])
		{
			while (y >= 0)
				free(map->map[y--]);
			free(map->map);
			return (false);
		}
		x = 0;
		while (x < map->x_max)
			map->map[y][x++] = SPACE;
		y++;
	}
	return (true);
}

t_bool	is_spawn(t_map_value value)
{
	if (value == PN || value == PS || value == PE || value == PW)
		return (true);
	return (false);
}

t_bool	fill_map(t_list *list, t_map *map)
{
	int		y;
	int		x;
	char	*line;
	int		spawn_count;

	y = 0;
	spawn_count = 0;
	while (list)
	{
		x = 0;
		line = list->content;
		while (line[x])
		{
			map->map[y][x] = map_content_to_map_value(line[x]);
			if (is_spawn(map->map[y][x]))
				spawn_count++;
			if (map->map[y][x] == ERR)
				return (false);
			x++;
		}
		y++;
		list = list->next;
	}
	return (true && spawn_count == 1 && check_closed_map(map));
}

t_bool	parse_map_list(t_list **list, char *line)
{
	t_list	*newnode;
	char	*copy;

	copy = ft_strtrim(line, "\n");
	if (!copy)
		return (free(line), false);
	if (!*list && *copy == '\0')
		return (free(line), free(copy), true);
	if (*list && *copy == '\0')
		return (free(line), free(copy), false);
	newnode = ft_lstnew(copy);
	if (!newnode)
		return (free(line), free(copy), false);
	ft_lstadd_back(list, newnode);
	free(line);
	return (true);
}
