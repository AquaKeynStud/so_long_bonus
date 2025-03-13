/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:55:15 by arocca            #+#    #+#             */
/*   Updated: 2025/03/13 15:04:23 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "parsing.h"

static bool	isnt_wall_surrounded(t_map *map, int width, int height)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0].type != '1' || map->map[i][width].type != '1')
			return (err("Error : The map must be surrounded by walls"));
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i].type != '1' || map->map[height][i].type != '1')
			return (err("Error : The map must be surrounded by walls"));
		i++;
	}
	return (false);
}

static bool	is_type_forbidden(t_case cell)
{
	return (type_of(cell) < 0);
}

static bool	double_player_error(t_case cell)
{
	return (cell.type == 'P');
}

static bool	double_exit_error(t_case cell)
{
	return (cell.type == 'E');
}

int	err_map_parsing(t_map *map, t_data *data)
{
	if (map->width == 0 && map->height == 0)
		return (err("The map file is empty"));
	if (map->width == map->height)
		return (err("Error : The map must not be a square"));
	if (isnt_wall_surrounded(map, map->width - 1, map->height - 1))
		return (1);
	if (browse_map(map, is_type_forbidden))
		return (err("The map contains unauthorized types"));
	if (browse_map(map, double_player_error) != 1)
		return (err("The map contains less or more than 1 player"));
	if (browse_map(map, double_exit_error) != 1)
		return (err("The map contains less or more than 1 exit"));
	if (map->collectible == 0)
		return (err("The map must contain at least one collectible"));
	bfs(map, data->pyx[1], data->pyx[0]);
	if (browse_map(map, is_item_unreachable))
		return (err("Some objects on the map are unreachable"));
	return (0);
}
