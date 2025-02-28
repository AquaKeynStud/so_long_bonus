/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:55:15 by arocca            #+#    #+#             */
/*   Updated: 2025/02/28 18:30:59 by arocca           ###   ########.fr       */
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

static bool	is_type_allowed(t_case cell)
{
	char	*types;

	types = "01PCE";
	while (*types)
	{
		if (*types++ == cell.type)
			return (true);
	}
	return (false);
}


int	err_map_parsing(t_map	*map)
{
	if (!is_wall_surrounded(map, map -> width - 1, map -> height - 1))
		return (err("Error : The map must be surrounded by walls !"));
	else if (!browse_map(map, is_type_allowed))
		return (err("Error : The map contains unauthorized types"));
	return (0);
}