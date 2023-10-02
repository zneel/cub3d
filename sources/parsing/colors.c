/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:46:54 by ebouvier          #+#    #+#             */
/*   Updated: 2023/10/02 15:18:04 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "parsing.h"

t_bool	check_color_int(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
			return (false);
		i++;
	}
	return (true);
}

t_bool	check_tree_colors(char *r, char *g, char *b)
{
	if (!check_color_int(r) || !check_color_int(g) || !check_color_int(b))
		return (false);
	return (true);
}

int	parse_color(char *r, char *g, char *b)
{
	int	ir;
	int	ig;
	int	ib;

	if (!check_tree_colors(r, g, b))
		return (-1);
	ir = ft_atoi(r);
	ig = ft_atoi(g);
	ib = ft_atoi(b);
	if ((ir > 255 || ig > 255 || ib > 255) || (ir < 0 || ig < 0 || ib < 0))
		return (-1);
	else
		return (ir << 16 | ig << 8 | ib);
}

t_bool	parse_ceiling_color(char *line, t_map *map)
{
	char	**colors;

	if (line[0] == 'C')
	{
		map->data.ceiling_bool++;
		colors = ft_split(line + 1, ", \n");
		if (!colors || !colors[0] || !colors[1] || !colors[2]
			|| split_len(colors) > 3)
		{
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
		map->data.floor_bool++;
		colors = ft_split(line + 1, ", \n");
		if (!colors || !colors[0] || !colors[1] || !colors[2]
			|| split_len(colors) > 3)
		{
			return (free_split(colors), false);
		}
		map->data.floor = parse_color(colors[0], colors[1], colors[2]);
		free_split(colors);
		return (true);
	}
	return (false);
}
