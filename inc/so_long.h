/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:51:04 by arocca            #+#    #+#             */
/*   Updated: 2025/02/24 12:44:26 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* -- Includes -- */
# include "mlx.h"
# include "mlx_int.h"
# include <stdlib.h>

/* -- Structures -- */
typedef struct s_data
{
	void	*mlx;
	void	*win;
}				t_data;

typedef struct s_case
{
	int		x;
	int		y;
	char	type;
}				t_case;

typedef struct	s_map
{
	int		width;
	int		height;
	t_case	**map;
}				t_map;

/* -- Fonctions -- */
void	get_map_size(const char *file, t_map *map_data);
void	get_map(const char *file);

#endif