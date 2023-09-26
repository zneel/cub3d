/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:57:59 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/26 13:58:08 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
