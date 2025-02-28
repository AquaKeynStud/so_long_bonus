/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:36:46 by arocca            #+#    #+#             */
/*   Updated: 2025/02/28 18:36:30 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

int	err(char *message)
{
	int	len;

	len = ft_strlen(message);
	ft_printf("\033[31m\033[1m\033[47m     ");
	ft_printf(message);
	ft_printf("     \033[0m\n");
	return (len);
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
