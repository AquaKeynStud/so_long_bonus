/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:40:53 by arocca            #+#    #+#             */
/*   Updated: 2025/03/10 14:30:58 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	forbidden_input(int keycode)
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
	if (keycode == KEY_W && data->pyx[0] - 1 < 0)
		return (false);
	if (keycode == KEY_A && data->pyx[1] - 1 < 0)
		return (false);
	if (keycode == KEY_S && data->pyx[0] + 1 > (*data->map)->height)
		return (false);
	if (keycode == KEY_D && data->pyx[1] + 1 > (*data->map)->width)
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
		aim = &map[data->pyx[0] - 1][data->pyx[1]];
	else if (keycode == KEY_A)
		aim = &map[data->pyx[0]][data->pyx[1] - 1];
	else if (keycode == KEY_S)
		aim = &map[data->pyx[0] + 1][data->pyx[1]];
	if (keycode == KEY_D)
		aim = &map[data->pyx[0]][data->pyx[1] + 1];
	if (keycode >= KEY_D && keycode <= KEY_W)
		move_player(data, *data->map, aim);
	return (0);
}
