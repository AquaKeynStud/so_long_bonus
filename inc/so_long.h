/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:51:04 by arocca            #+#    #+#             */
/*   Updated: 2025/03/03 12:48:19 by arocca           ###   ########.fr       */
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

typedef struct s_queue
{
	t_case	**q;
	int		front;
	int		rear;
	int		size;
}				t_queue;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	*map_data;
}				t_data;

/* -- main functions -- */
int	close_window(t_data *data, int exit_code);

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
void	print_map(t_map *map);

/* -- Utils -- */
int		get_asset_pos(t_map *map, char asset, char axis);
int		browse_map(t_map *map, bool (*function)(t_case cell));

#endif