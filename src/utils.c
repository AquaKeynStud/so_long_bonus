/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:51:56 by arocca            #+#    #+#             */
/*   Updated: 2025/03/03 12:31:08 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	browse_map(t_map *map, bool (*function)(t_case cell))
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (function(map->map[i][j]))
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

int	get_asset_pos(t_map *map, char asset, char axis)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j].type == asset && axis == 'x')
				return (map->map[i][j].x);
			else if (map->map[i][j].type == asset && axis == 'y')
				return (map->map[i][j].y);
			j++;
		}
		i++;
	}
	return (0);
}