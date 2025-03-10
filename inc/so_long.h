/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:51:04 by arocca            #+#    #+#             */
/*   Updated: 2025/03/10 15:48:41 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* -- Includes -- */
# include <stdlib.h>
# include <stdbool.h>
# include "mlx.h"
# include "mlx_int.h"
# include "ft_printf.h"

/* -- Structures -- */
typedef struct s_images
{
	void	*wall;
	void	*floor;
	void	*collec;
	void	*player;
	void	*exit;
}				t_images;

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

typedef struct s_data
{
	bool		keys[256];
	int			pyx[2];
	int			collectible;
	int			moves;
	int			winw;
	int			winh;
	void		*mlx;
	void		*win;
	t_images	*images;
	t_map		**map;
}				t_data;

/* -- macros -- */
# define SX 64
# define SY 64
# define MAXH 18
# define MAXW 30

# define CHARW 6

# define KEY_ESC 65307
# define KEY_W 122 // 119
# define KEY_A 113 // 97
# define KEY_S 115
# define KEY_D 100

# define BLACK 0x000000
# define WHITE 0xFFFFFF

/* -- Main functions -- */
int		close_window(t_data *data, int exit_code);

/* -- Map functions -- */
bool	free_map(t_map **map);
bool	get_map(const char *file, t_map **map_data, t_data *data);

/* -- Input functions -- */
int 	key_pressed(int keycode, t_data *data);
int 	key_released(int keycode, t_data *data);
int		handle_keypress(int keycode, t_data *data);
bool	move_player(t_data *data, t_map *map, t_case *aim);

/* -- Images functions -- */
bool	init_images(void *mlx, t_images *img);

void	free_images(t_data *data, t_images *img);
void	update_images(t_data *data, t_case *aim, int x, int y);
void	print_on_win(t_data *data, int *axis, int color, char *txt);
void	display_images(void *m, void *w, t_images img, t_map *map_data);
void	display_player(t_data *data, int *pos, t_images img, t_map *map_data);

/* -- Print functions -- */
int		err(char *message);
int		err_errno(int errnum);
int		err_v(char *message, char *value);

void	print_map(t_map *map);
void	print_win(t_data *data, int pos[2], char *text, int moves);

/* -- Utils -- */
char	*ft_itoa(int n);

int		find_type(t_case cell);
int		get_pos(t_map *map, char axis);
int		browse_map(t_map *map, bool (*function)(t_case cell));
int		*get_axis(int tab[2], int x, int y);

void	*get_img(t_images img, int type);

#endif