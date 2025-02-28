/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:51:04 by arocca            #+#    #+#             */
/*   Updated: 2025/02/28 18:27:46 by arocca           ###   ########.fr       */
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

typedef struct s_map
{
	int		width;
	int		height;
	t_case	**map;
}				t_map;

/* -- main functions -- */
int	close_window(t_data *data, int exit_code);

/* -- maps functions -- */
bool	get_map(const char *file, t_map *map_data);

/* -- parsing functions -- */
int		err_map_parsing(t_map	*map);

/* -- input functions -- */
int		handle_keypress(int keycode, t_data *data);

/* -- print functions -- */
int		err(char *message);
void	print_map(t_map *map);

/* -- Utils -- */
bool	browse_map(t_map *map, bool (*function)(t_case cell));

#endif