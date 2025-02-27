/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:36:46 by arocca            #+#    #+#             */
/*   Updated: 2025/02/27 18:00:01 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err(char *message)
{
	write(2, "\033[31m\033[1m", 0);
	write(2, message, ft_strlen(message));
	write(2, "\033[0m", 0);
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map -> height)
	{
		j = 0;
		while (j < map -> width)
		{
			ft_printf("(%d, %d)", map -> map[i][j].x, map -> map[i][j].y);
			ft_printf(" -> %c\n", map -> map[i][j].type);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
