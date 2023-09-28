/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:31:40 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/28 19:31:20 by mhoyer           ###   ########.fr       */
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
	ft_dprintf(2, "Error\n%s\n", str);
	exit(1);
}

void	perror_and_exit(char *prefix)
{
	ft_dprintf(2, "Error\n");
	perror(prefix);
	exit(1);
}
