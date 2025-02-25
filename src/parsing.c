/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:55:15 by arocca            #+#    #+#             */
/*   Updated: 2025/02/25 23:52:34 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_size_err(const char *file, t_map *map) // Renvoie 1 en cas d'erreur et 0 en cas de succès
{
	int		fd;
	int		count;
	char	c;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("The map you're trying to open doesn't exist..."));
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			if (count == 0 || (map -> width != 0 && count != map -> width))
				return (1);
			map -> width = count;
			map -> height++;
			count = 0;
		}
		else
			count++;
	}
	if (count && count == map -> width)
		map -> height++;
	if (map -> width == map -> height)
		return (1);
	return (close(fd));
}