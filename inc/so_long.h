/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:51:04 by arocca            #+#    #+#             */
/*   Updated: 2025/03/06 16:36:49 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* -- Includes -- */
# include "mlx.h"
# include "mlx_int.h"
# include "ft_printf.h"
# include "map.h"
# include <stdlib.h>
# include <stdbool.h>

/* -- Structures -- */
typedef struct s_data
{
	void	*mlx;
	void	*win;
}				t_data;

typedef struct s_images
{
	void	*wall;
	void	*floor;
	void	*collec;
	void	*player;
	void	*exit;
}				t_images;

/* -- macros -- */
# define SX 64
# define SY 64

/* -- Main functions -- */
int		close_window(t_data *data, int exit_code);

/* -- Input functions -- */
int		handle_keypress(int keycode, t_data *data);

/* -- Images functions -- */
bool	init_images(void *mlx, t_images *img);

void	free_images(t_data *data, t_images *img);
void	display_images(void *m, void *w, t_images *img, t_map *map_data);

/* -- Utils -- */
int		get_asset_pos(t_map *map, char asset, char axis);
int		browse_map(t_map *map, bool (*function)(t_case cell));
int		find_type(t_case cell);
void	*get_img(t_images *img, int type);

#endif