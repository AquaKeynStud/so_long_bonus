/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:51:04 by arocca            #+#    #+#             */
/*   Updated: 2025/03/05 16:40:15 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* -- Includes -- */
# include "mlx.h"
# include "mlx_int.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>

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
	bool	verified;
}				t_case;

typedef struct s_map
{
	int		width;
	int		height;
	t_case	**map;
}				t_map;

typedef struct s_images
{
	void	*wall;
	void	*floor;
	void	*collec;
	void	*player;
	void	*exit;
}				t_images;

typedef struct s_queue
{
	t_case	**q;
	int		front;
	int		rear;
	int		size;
}				t_queue;

/* -- macros -- */
# define SX 64
# define SY 64

/* -- main functions -- */
int		close_window(t_data *data, int exit_code);

/* -- maps functions -- */
bool	free_map(t_map **map);
bool	get_map(const char *file, t_map **map_data);

/* -- parsing functions -- */
int		err_map_parsing(t_map	*map);
void	bfs(t_map *map, int start_x, int start_y);
bool	is_item_unreachable(t_case cell);

/* -- input functions -- */
int		handle_keypress(int keycode, t_data *data);

/* -- print functions -- */
int		err(char *message);
int		err_v(char *message, char *value);
int		err_errno(int errnum);
void	print_map(t_map *map);

/* -- Utils -- */
int		get_asset_pos(t_map *map, char asset, char axis);
int		browse_map(t_map *map, bool (*function)(t_case cell));
int		find_type(t_case cell);
void	*get_img(t_images *img, int type);

/* -- assets functions -- */
bool	init_images(void *mlx, t_images *img);
void	display_images(void *m, void *w, t_images *img, t_map *map_data);
void	free_images(t_data *data, t_images *img);

#endif