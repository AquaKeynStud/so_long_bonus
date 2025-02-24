/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:44:33 by arocca            #+#    #+#             */
/*   Updated: 2025/02/24 18:05:58 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

int	map_size_err(const char *file, t_map *map) // Renvoie 1 en cas d'erreur et 0 en cas de succès
{
	int		fd;
	int		count;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
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
	if (map -> width == map -> height)
		return (1);
	return (close(fd));
}

void	free_map(t_map *map)
{
	int i;

	if (map == NULL)
		return ;
	i = 0;
	if (map -> map)
	{
		while (map -> map[i] != NULL)
		{
			free(map -> map[i]); 
			i++;
		}
		free(map -> map);
		map -> map = NULL;
	}
	free(map);
	map = NULL;
}

void	init_map(t_map *map_data)
{
	int		i;
	int		j;

	i = 0;
	map_data -> map = malloc(sizeof(t_case *) * (map_data -> height + 1));
	if (!map_data -> map)
		return ;
	while (i < map_data -> height)
	{
		map_data -> map[i] = malloc(sizeof(t_case) * map_data -> width);
		if (!map_data -> map[i])
			return (free_map(map_data));
		j = 0;
		while (j < map_data -> width)
		{
			map_data -> map[i][j].x = i;
			map_data -> map[i][j].y = j;
			map_data -> map[i][j].type = '\0';
			j++;
		}
		i++;
	}
	map_data -> map[i] = NULL;
}

void	fill_map(const char *file, t_map *map)
{
	char	c;
	int		i;
	int		j;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	while (i < map -> height)
	{
		j = 0;
		while (j < map -> width)
		{
			read(fd, &c, 1);
			map -> map[i][j].type = c;
			j++;
		}
		read(fd, &c, 1);
		i++;
	}
	close(fd);
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
			printf("Case (%d, %d) -> %c\n", map -> map[i][j].x, map -> map[i][j].y, map -> map[i][j].type);
			j++;
		}
		printf("\n");
		i++;
	}
}

t_map	*get_map(const char *file, t_map *map_data)
{
	map_data = malloc(sizeof(t_map));
	if (!map_data)
		return ;
	map_data -> width = 0;
	map_data -> height = 0;
	map_size_err(file, map_data);
	printf("%i, %i\n", map_data -> width, map_data -> height);
	init_map(map_data);
	fill_map(file, map_data);
	print_map(map_data);
	free_map(map_data);
	return ;
}