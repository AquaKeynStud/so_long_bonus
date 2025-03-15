/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:09:14 by arocca            #+#    #+#             */
/*   Updated: 2025/03/15 10:56:58 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map -> height)
	{
		j = 0;
		while (j < map -> width)
			ft_printf("[%i, %i] ", i, j++);
		ft_printf("\n");
		j = 0;
		while (j < map -> width)
		{
			ft_printf(" %c ", map->map[i][j].type);
			if (map -> map[i][j].verified)
				ft_printf("✅  ");
			else
				ft_printf("❌  ");
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_verification(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map -> height)
	{
		j = 0;
		while (j < map -> width)
		{
			if (map -> map[i][j].verified)
				ft_printf("✅ ");
			else
				ft_printf("❌ ");
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_map_types(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map -> height)
	{
		j = 0;
		while (j < map -> width)
		{
			ft_printf("%c ", map->map[i][j].type);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_map_matrices(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map -> height)
	{
		j = 0;
		while (j < map -> width)
		{
			ft_printf("[%i, %i] ", i, j);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}