/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:55:15 by arocca            #+#    #+#             */
/*   Updated: 2025/02/27 17:52:12 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_size_err(const char *file, t_map *map)
{
	int		fd;
	int		count;
	char	c;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("The map you're trying to open doesn't exist..."));
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			if (count == 0 || (map -> width != 0 && count != map -> width))
				return (1);
			map -> width = count;
			map -> height++;
			count = 0;
		}
		else
			count++;
	}
	if (count && count == map -> width)
		map -> height++;
	close(fd);
	return (0);
}

bool	is_wall_surrounded(t_map *map)
{
	int	i;
	int	height;
	int	width;

	i = 0;
	height = map -> height - 1;
	width = map -> width - 1;
	if (map -> height == map -> width)
		return (false);
	while (i < map -> height)
	{
		if (map -> map[i][0].type != '1' || map -> map[i][width].type != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < map -> width)
	{
		if (map -> map[0][i].type != '1' || map -> map[height][i].type != '1')
			return (false);
		i++;
	}
	return (true);
}
