/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:44:33 by arocca            #+#    #+#             */
/*   Updated: 2025/02/24 11:31:06 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

void	get_map_size(const char *file, int *width, int *height)
{
	int		fd;
	int		actual_width;
	char	c;

	actual_width = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			(*width) = actual_width;
			actual_width = 0;
			(*height)++;
		}
		else
			actual_width++;
	}
	if (actual_width > 0)
		(*height)++;
	close(fd);
}

t_case	**free_map(t_case **map)
{
	int	i;
	
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return (NULL);
}

t_case	**init_map(int width, int height)
{
	t_case	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = malloc(sizeof(t_case *) * height);
	if (!map)
		return (NULL);
	while (i < height)
	{
		map[i] = malloc(sizeof(t_case) * width);
		if (!map[i])
			return (free_map(map));
		while (j < width)
		{
			map[i][j].x = i;
			map[i][j].y = j;
			map[i][j].type = '\0';
			j++;
		}
		i++;
	}
	return (map);
}
