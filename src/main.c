/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:45:44 by arocca            #+#    #+#             */
/*   Updated: 2025/03/03 12:55:43 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data, int exit_code)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map_data)
		free_map(&data->map_data);
	if (exit_code == EXIT_SUCCESS)
		ft_printf("\033[32m\033[47m\033[1m    • So_Long ended •    \033[0m\n");
	exit(exit_code);
}

bool	mlx_create(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (false);
	data->win = mlx_new_window(data->mlx, 800, 600, "so_long");
	if (!data->win)
	{
		free(data->mlx);
		return (false);
	}
	return (true);
}

int	main(void)
{
	t_data	data;
	t_map	*map_data;

	map_data = NULL;
	if (!mlx_create(&data))
		return (err("Error : Something went wrong during window creation"));
	if (!get_map("./maps/map.ber", &map_data))
		return (close_window(&data, EXIT_FAILURE));
	data.map_data = map_data;
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_key_hook(data.win, handle_keypress, &data);
	mlx_loop(data.mlx);
	return (0);
}
