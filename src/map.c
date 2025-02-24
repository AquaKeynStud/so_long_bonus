/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:44:33 by arocca            #+#    #+#             */
/*   Updated: 2025/02/24 12:47:57 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

void	get_map_size(const char *file, t_map *map_data)
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
			map_data -> width = actual_width;
			actual_width = 0;
			map_data -> height++;
		}
		else
			actual_width++;
	}
	if (actual_width > 0)
		map_data -> height++;
	close(fd);
}

t_case	**free_map(t_case **map)
{
    int i;

    if (map == NULL)
        return (NULL);
    i = 0;
    while (map[i] != NULL)
    {
        free(map[i]); 
        i++;
    }
    free(map);
	map = NULL;
	return (NULL);
}

t_case	**init_map(int width, int height)
{
	t_case	**map;
	int		i;
	int		j;

	i = 0;
	map = malloc(sizeof(t_case *) * (height + 1));
	if (!map)
		return (NULL);
	while (i < height)
	{
		map[i] = malloc(sizeof(t_case) * width);
		if (!map[i])
			return (free_map(map));
		j = 0;
		while (j < width)
		{
			map[i][j].x = i;
			map[i][j].y = j;
			map[i][j].type = '\0';
			j++;
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	print_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map -> height)
	{
		j = 0;
		while (j < map -> width)
		{
			// Affiche les coordonnées (x, y) et le type de chaque case
			printf("Case (%d, %d)\n", map -> map[i][j].x, map -> map[i][j].y);
			j++;
		}
		i++;
	}
}

void	get_map(const char *file)
{
	t_map	*map_data;

	map_data = malloc(sizeof(t_map));
	if (!map_data)
		return ;
	map_data -> width = 0;
	map_data -> height = 0;
	get_map_size(file, map_data);
	printf("%i, %i\n", map_data -> width, map_data -> height);
	map_data -> map = init_map(map_data -> width, map_data -> height);
	print_map(map_data);
	free_map(map_data -> map);
	free(map_data);
	map_data = NULL;
	return ;
}