/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:44:33 by arocca            #+#    #+#             */
/*   Updated: 2025/03/10 09:19:15 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"
#include "so_long.h"
#include "parsing.h"
#include <fcntl.h>
#include <unistd.h>

static int	map_size_init_err(const char *file, t_map *map)
{
	int		fd;
	int		count;
	char	c;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (err_errno(errno));
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			if (count == 0 || (map->width != 0 && count != map->width))
				return (err("The map size is invalid"));
			map->width = count;
			map->height++;
			count = 0;
		}
		else
			count++;
	}
	if (count && count == map->width)
		map->height++;
	close(fd);
	return (0);
}

bool	free_map(t_map **map)
{
	int	i;

	if (!(*map))
		return (false);
	i = 0;
	if ((*map)->map)
	{
		while ((*map)->map[i] != NULL)
		{
			free((*map)->map[i]);
			i++;
		}
		free((*map)->map);
		(*map)->map = NULL;
	}
	free(*map);
	(*map) = NULL;
	return (false);
}

static bool	init_map(t_map *map_data)
{
	int		i;
	int		j;

	i = 0;
	map_data->map = malloc(sizeof(t_case *) * (map_data->height + 1));
	if (!map_data->map)
		return (false);
	while (i < map_data->height)
	{
		map_data->map[i] = malloc(sizeof(t_case) * map_data->width);
		if (!map_data->map[i])
			return (free_map(&map_data));
		j = 0;
		while (j < map_data->width)
		{
			map_data->map[i][j].x = j;
			map_data->map[i][j].y = i;
			map_data->map[i][j].type = '\0';
			map_data->map[i][j].verified = false;
			j++;
		}
		i++;
	}
	map_data->map[i] = NULL;
	return (true);
}

static void	fill_map(const char *file, t_map *map, t_data *data)
{
	char	c;
	int		i;
	int		j;
	int		fd;

	i = 0;
	data->collectible = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			read(fd, &c, 1);
			map->map[i][j].type = c;
			if (c == 'C')
				data->collectible++;
			j++;
		}
		read(fd, &c, 1);
		i++;
	}
	close(fd);
}

bool	get_map(const char *file, t_map **map_data, t_data *data)
{
	(*map_data) = malloc(sizeof(t_map));
	if (!(*map_data))
		return (false);
	(*map_data)->width = 0;
	(*map_data)->height = 0;
	if (map_size_init_err(file, (*map_data)))
		return (free_map(map_data));
	init_map(*map_data);
	fill_map(file, (*map_data), data);
	get_axis(data->pos, get_pos(*map_data, 'y'), get_pos(*map_data, 'x'));
	if (err_map_parsing(*map_data, data))
		return (free_map(map_data));
	data->map = map_data;
	return (true);
}
