/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:12:12 by mhoyer            #+#    #+#             */
/*   Updated: 2023/09/26 12:08:05 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include "lists.h"
#include "parsing.h"
#include <fcntl.h>

void	print_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->y_max)
	{
		x = 0;
		while (x < map->x_max)
		{
			printf("%d", map->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	debug_parsing(t_map *map)
{
	printf("NO:%s\n", map->data.no);
	printf("SO:%s\n", map->data.so);
	printf("EA:%s\n", map->data.ea);
	printf("WE:%s\n", map->data.we);
	printf("F:#%X\n", map->data.floor);
	printf("C:#%X\n", map->data.ceiling);
	printf("map:\n");
	print_map(map);
}

int	get_x_max(t_list *list)
{
	int	max;

	max = 0;
	while (list)
	{
		if ((int)ft_strlen(list->content) > max)
			max = ft_strlen(list->content);
		list = list->next;
	}
	return (max);
}

t_map_value	map_content_to_map_value(char content)
{
	if (content == '0')
		return (EMPTY);
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
			map->map[y][x++] = WALL;
		y++;
	}
	return (true);
}

t_bool	fill_map(t_list *list, t_map *map)
{
	int		y;
	int		x;
	char	*line;

	y = 0;
	while (list)
	{
		x = 0;
		line = list->content;
		while (line[x])
		{
			if (ft_isspace(line[x]))
				;
			else
			{
				map->map[y][x] = map_content_to_map_value(line[x]);
				if (map->map[y][x] == ERR)
					return (false);
			}
			x++;
		}
		y++;
		list = list->next;
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
		destroy_map(map);
		return (false);
	}
	return (true);
}

t_bool	parse_infos(char *line, t_map *map)
{
	if (parse_textures(line, map) || parse_ceiling_color(line, map)
		|| parse_floor_color(line, map))
		return (true);
	return (false);
}

t_bool	parse_data(int fd, t_map *map)
{
	char	*line;
	t_list	*list;
	t_bool	ok;

	list = NULL;
	ok = true;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (parse_infos(line, map))
		{
			free(line);
			continue ;
		}
		else
			parse_map_list(&list, line, map);
		free(line);
	}
	if (!lst_to_map(list, map))
		ok = false;
	ft_lstclear(&list, free);
	close(fd);
	return (ok);
}

t_bool	parse_cubfile(char *file, t_map *map)
{
	int	fd;

	check_file(file);
	fd = open(file, O_RDONLY, 0644);
	if (fd == -1)
		perror_and_exit(file);
	if (!parse_data(fd, map))
	{
		destroy_map(map);
		return (false);
	}
	if (!is_scene_valid(map))
	{
		destroy_map(map);
		return (false);
	}
	debug_parsing(map);
	return (true);
}
