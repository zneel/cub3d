/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:31:40 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/24 20:39:24 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"

void	error_and_exit(char *str)
{
	ft_dprintf(2, "Error\n%s\n", str);
	exit(1);
}

void	perror_and_exit(char *prefix)
{
	ft_dprintf(2, "Error\n");
	perror(prefix);
	exit(1);
}
