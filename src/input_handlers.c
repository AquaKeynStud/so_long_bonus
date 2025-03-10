/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:40:53 by arocca            #+#    #+#             */
/*   Updated: 2025/03/10 12:31:48 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "printers.h"

bool	move_player(t_data *data, t_map *map, t_case *aim)
{
	int		x;
	int		y;
	int		pos[2];

	y = data->pos[0];
	x = data->pos[1];
	if (aim->type == '1')
		return (true);
	else if (aim->type == 'E' && data->collectible != 0)
		return (err("You must have collected all the eggs before exiting !"));
	if (aim->type == 'C')
		data->collectible--;
	else if (aim->type == 'E')
		return (mlx_loop_end(data->mlx));
	map->map[y][x].type = '0';
	aim->type = 'P';
	if (map->height > MAXW || map->width > MAXW)
		display_player(data, get_axis(pos, aim->x, aim->y), *data->images, map);
	else
		update_images(data, aim, data->pos[1], data->pos[0]);
	data->pos[0] = aim->y;
	data->pos[1] = aim->x;
	print_win(data, get_axis(pos, 0, data->winh - 5), "Moves :", ++data->moves);
	return (true);
}

bool	forbidden_input(int keycode)
{
	int	input[5];
	int	i;

	i = 0;
	input[0] = KEY_ESC;
	input[1] = KEY_W;
	input[2] = KEY_A;
	input[3] = KEY_S;
	input[4] = KEY_D;
	while (i < 5)
	{
		if (keycode == input[i++])
			return (false);
	}
	return (true);
}

static bool	update_target(int keycode, t_data *data)
{
	if (keycode == KEY_W && data->pos[0] - 1 < 0)
		return (false);
	if (keycode == KEY_A && data->pos[1] - 1 < 0)
		return (false);
	if (keycode == KEY_S && data->pos[0] + 1 > (*data->map)->height)
		return (false);
	if (keycode == KEY_D && data->pos[1] + 1 > (*data->map)->width)
		return (false);
	return (true);
}

int	handle_keypress(int keycode, t_data *data)
{
	t_case		**map;
	t_case		*aim;

	map = (*data->map)->map;
	if (forbidden_input(keycode))
		return (ft_printf("Cette touche n'est pas attribuée\n"));
	if (keycode == KEY_ESC)
		return (mlx_loop_end(data->mlx));
	if (!update_target(keycode, data))
		return (err("Vous ne pouvez pas aller par là !"));
	if (keycode == KEY_W)
		aim = &map[data->pos[0] - 1][data->pos[1]];
	else if (keycode == KEY_A)
		aim = &map[data->pos[0]][data->pos[1] - 1];
	else if (keycode == KEY_S)
		aim = &map[data->pos[0] + 1][data->pos[1]];
	if (keycode == KEY_D)
		aim = &map[data->pos[0]][data->pos[1] + 1];
	if (keycode >= KEY_D && keycode <= KEY_W)
		move_player(data, *data->map, aim);
	return (0);
}
