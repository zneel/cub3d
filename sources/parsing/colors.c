/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:46:54 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/26 15:06:03 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	check_color_int(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (!ft_isdigit(c[i++]))
			return (false);
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

	// if (!check_tree_colors(r, g, b))
	// 	return (-1);
	ir = ft_atoi(r);
	ig = ft_atoi(g);
	ib = ft_atoi(b);
	if ((ir > 255 || ig > 255 || ib > 255) || (ir < 0 || ig < 0 || ib < 0))
		return (-1);
	else
		return (ir << 16 | ig << 8 | ib);
}
