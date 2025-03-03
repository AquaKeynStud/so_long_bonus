/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:55:15 by arocca            #+#    #+#             */
/*   Updated: 2025/03/03 12:55:56 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_wall_surrounded(t_map *map, int width, int height)
{
	int	i;

	i = 0;
	if (width == height)
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

static bool	is_type_forbidden(t_case cell)
{
	char	*types;

	types = "01PCE";
	while (*types)
	{
		if (*types++ == cell.type)
			return (false);
	}
	return (true);
}

static bool	double_player_error(t_case cell)
{
	return (cell.type == 'P');
}

static bool	double_exit_error(t_case cell)
{
	return (cell.type == 'E');
}

int	err_map_parsing(t_map	*map)
{
	if (!is_wall_surrounded(map, map -> width - 1, map -> height - 1))
		return (err("The map and be rectangular and surrounded by walls"));
	if (browse_map(map, is_type_forbidden))
		return (err("The map contains unauthorized types"));
	if (browse_map(map, double_player_error) != 1)
		return (err("The map contains less or more than 1 player"));
	if (browse_map(map, double_exit_error) != 1)
		return (err("The map contains less or more than 1 exit"));
	bfs(map, 5, 5);
	if (browse_map(map, is_item_unreachable))
		return (err("The map contains less or more than 1 exit"));
	return (0);
}
