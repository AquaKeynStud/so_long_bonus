/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:51:04 by arocca            #+#    #+#             */
/*   Updated: 2025/02/24 10:26:05 by arocca           ###   ########.fr       */
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
	char	**map;
}				t_data;

typedef struct s_case
{
	int		x;
	int		y;
	char	type;
}				t_case;

/* -- Fonctions -- */
void	get_map_size(const char *file, int *width, int *height);

#endif