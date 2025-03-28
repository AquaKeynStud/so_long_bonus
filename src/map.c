/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:44:33 by arocca            #+#    #+#             */
/*   Updated: 2025/03/25 18:57:41 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <errno.h>
#include "parsing.h"
#include "printers.h"

bool	free_map(t_map **map)
{
	t_case	**tmp;

	if (!map || !(*map))
		return (false);
	if ((*map)->map)
	{
		tmp = (*map)->map;
		while (*tmp)
			free(*tmp++);
		free((*map)->map);
		(*map)->map = NULL;
	}
	free((*map)->slime);
	(*map)->slime = NULL;
	free(*map);
	*map = NULL;
	return (false);
}

static int	map_size_init_err(const char *file, int *width, int *height)
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
			if (!count || ((*width) && count != (*width)) || (*width > 28000))
				return (close(fd) + err("The map size is invalid"));
			(*width) = count;
			(*height)++;
			count = 0;
		}
		else
			count++;
	}
	if (count && count == (*width))
		(*height)++;
	return (close(fd));
}

static bool	init_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	map->map = malloc(sizeof(t_case *) * (map->height + 1));
	if (!map->map)
		return (false);
	while (i < map->height)
	{
		map->map[i] = malloc(sizeof(t_case) * map->width);
		if (!map->map[i])
			return (free_map(&map));
		j = 0;
		while (j < map->width)
		{
			map->map[i][j].x = j;
			map->map[i][j].y = i;
			map->map[i][j].rand_asset = rand() % 4;
			map->map[i][j].verified = false;
			j++;
		}
		i++;
	}
	map->map[i] = NULL;
	return (true);
}

static void	fill_map(const char *file, t_map *map)
{
	char	c;
	int		i;
	int		j;
	int		fd;

	i = 0;
	map->items = 0;
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
				map->items++;
			j++;
		}
		read(fd, &c, 1);
		i++;
	}
	close(fd);
}

bool	get_map(const char *file, t_map **map, t_data *data)
{
	(*map) = malloc(sizeof(t_map));
	if (!(*map))
		return (false);
	(*map)->width = 0;
	(*map)->height = 0;
	print_info_str("🧭 Start reading attempt on 🗺️  %s 🗺️ ", (char *)file);
	if (map_size_init_err(file, &(*map)->width, &(*map)->height))
		return (free_map(map));
	if ((*map)->height > 27000)
	{
		err("📛 Error : Map height is too big");
		return (free_map(map));
	}
	print_info_str("🌅 Starting creation of map... 🧪", NULL);
	init_map(*map);
	print_info_str("🍲 Start filling the map... 🀄", NULL);
	fill_map(file, (*map));
	get_axis(data->pyx, get_pos(*map, 'y'), get_pos(*map, 'x'));
	if (err_map_parsing(*map, data, file) || !get_slimes(*map))
		return (free_map(map));
	data->map = map;
	print_info_int("🏔️  Map size : %ix%i 🏞️ ", (*map)->width, (*map)->height);
	return (true);
}
