/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:14:55 by arocca            #+#    #+#             */
/*   Updated: 2025/03/06 16:17:02 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

/* -- Includes -- */
# include <stdlib.h>
# include <stdbool.h>

/* -- Structures -- */
typedef struct s_case
{
	int		x;
	int		y;
	char	type;
	bool	verified;
}				t_case;

typedef struct s_map
{
	int		width;
	int		height;
	t_case	**map;
}				t_map;

/* -- Functions -- */
bool	free_map(t_map **map);
bool	get_map(const char *file, t_map **map_data);

#endif
