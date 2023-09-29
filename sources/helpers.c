/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:31:40 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/29 14:54:04 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	error_and_exit(char *str)
{
	ft_dprintf(1, "Error\n%s\n", str);
	exit(1);
}

void	perror_and_exit(char *prefix)
{
	ft_dprintf(1, "Error\n");
	perror(prefix);
	exit(1);
}
