/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:51:56 by arocca            #+#    #+#             */
/*   Updated: 2025/02/27 18:07:13 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	browse_map(t_map *map, bool (*function)(t_case cell))
{
	int	i;
	int	j;

	i = 0;
	while (i < map -> height)
	{
		j = 0;
		while (j < map -> width)
		{
			if (!function(map -> map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
