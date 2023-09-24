/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:29:31 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/24 14:46:02 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

t_bool	valid_ext(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len < 4)
		return (false);
	if (name[len - 1] != 'b' || name[len - 2] != 'u' || name[len - 3] != 'c'
		|| name[len - 4] != '.')
		return (false);
	return (true);
}

void	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_and_exit("Error\nFile not found.");
	if (!valid_ext(file))
		print_and_exit("Error\nInvalid file extension.");
	close(fd);
}
