/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouvier <ebouvier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:29:31 by ebouvier          #+#    #+#             */
/*   Updated: 2023/09/28 16:09:48 by ebouvier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <fcntl.h>

int	split_len(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		;
	return (i);
}

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

t_bool	check_random(int fd)
{
	char	*line;
	int		i;

	while (true)
	{
		i = -1;
		line = get_next_line(fd);
		if (!line)
			break ;
		while (line[++i])
		{
			if (!ft_isascii(line[i]))
			{
				free(line);
				get_next_line(-1);
				return (false);
			}
		}
		free(line);
		i++;
	}
	return (true);
}

void	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDWR, 0644);
	if (fd == -1)
		perror_and_exit(file);
	if (!valid_ext(file))
	{
		close(fd);
		error_and_exit("Invalid file extension.");
	}
	if (!check_random(fd))
	{
		close(fd);
		error_and_exit("Invalid file.");
	}
	close(fd);
}
