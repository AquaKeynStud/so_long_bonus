/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:40:53 by arocca            #+#    #+#             */
/*   Updated: 2025/03/07 16:00:08 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "printers.h"

bool	move_player(t_data *data, t_map *map, t_images images, t_case target)
{
	int	x;
	int	y;

	x = data->pos[1];
	y = data->pos[0];
	if (x < 0 || x > map->width || y < 0 || y > map->height)
		return (err("The player is in a forbidden area !"));
	if (target.type == '1')
		return (true);
	else if (target.type == 'E' && data->collectible != 0)
		return (err("You must have collected all the eggs before exiting !"), ft_printf("%i\n", data->collectible));
	if (target.type == 'C')
		data->collectible--;
	else if (target.type == 'E')
		return (mlx_loop_end(data->mlx));
	map->map[y][x].type = '0';
	target.type = 'P';
	mlx_put_image_to_window(data->mlx, data->win, images.floor, x * SX, y * SY);
	mlx_put_image_to_window(data->mlx, data->win, images.player, (x + 1) * SX, y * SY);
	data->pos[0] = target.x;
	data->pos[1] = target.y;
	return (true);
}

bool forbidden_input(int keycode)
{
	int input[2];
	int	i;

	i = 0;
	input[0] = 65307;
	input[1] = 100;
	while (i < 2)
	{
		if (keycode == input[i++])
			return (false);
	}
	return (true);
}

int	handle_keypress(int keycode, t_data *data)
{
	t_map 		*map;
	t_images	images;
	t_case		target;

	map = *data->map;
	images = *data->images;
	if (forbidden_input(keycode))
		return (ft_printf("Cette touche n'est pas attribuée\n"));
	if (keycode == 65307)
		return (mlx_loop_end(data->mlx));
	if (keycode == 100)
		target = map->map[data->pos[1]][data->pos[0] + 1];
	if (keycode == 100) // Ajouter les autres
		move_player(data, map, images, target);
	return (0);
}
