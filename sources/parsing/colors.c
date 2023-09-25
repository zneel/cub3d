/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:46:54 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/25 09:53:20 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	parse_color(char *r, char *g, char *b)
{
	int ir;
	int ig;
	int ib;

	ir = ft_atoi(r);
	ig = ft_atoi(g);
	ib = ft_atoi(b);
	if ((ir > 255 || ig > 255 || ib > 255) || (ir < 0 || ig < 0 || ib < 0))
		return (-1);
	else
		return (ir << 16 | ig << 8 | ib);
}