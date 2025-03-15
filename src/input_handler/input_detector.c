/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:40:53 by arocca            #+#    #+#             */
/*   Updated: 2025/03/15 11:42:57 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_input(int keycode)
{
	int	input[5];
	int	i;

	i = 0;
	input[0] = KEY_ESC;
	input[1] = KEY_S;
	input[2] = KEY_D;
	input[3] = KEY_A;
	input[4] = KEY_W;
	while (i < 5)
	{
		if (keycode == input[i])
			return (i);
		i++;
	}
	return (-1);
}

static void	update_direction(int keycode, t_data *data)
{
	t_images	*image;

	image = data->images;
	if (check_input(keycode) > 0)
		image->direction = check_input(keycode) - 1;
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		data->keys[0] = true;
	else if (check_input(keycode) >= 0)
		data->keys[keycode] = true;
	else
		return (1);
	handle_keypress(keycode, data);
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		data->keys[0] = false;
	else if (check_input(keycode) >= 0)
		data->keys[keycode] = false;
	else
		return (1);
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	t_case		**map;
	t_case		*aim;

	map = (*data->map)->map;
	if (check_input(keycode) < 0)
		return (ft_printf("🫧 Cette touche n'est pas attribuée 🫧\n"));
	if (keycode == KEY_ESC)
		return (mlx_loop_end(data->mlx));
	if (keycode == KEY_W)
		aim = &map[data->pyx[0] - 1][data->pyx[1]];
	else if (keycode == KEY_A)
		aim = &map[data->pyx[0]][data->pyx[1] - 1];
	else if (keycode == KEY_S)
		aim = &map[data->pyx[0] + 1][data->pyx[1]];
	if (keycode == KEY_D)
		aim = &map[data->pyx[0]][data->pyx[1] + 1];
	update_direction(keycode, data);
	if (keycode >= KEY_D && keycode <= KEY_W)
		move_player(data, *data->map, aim);
	return (0);
}
