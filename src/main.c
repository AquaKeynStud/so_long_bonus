/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:45:44 by arocca            #+#    #+#             */
/*   Updated: 2025/03/05 18:26:28 by arocca           ###   ########.fr       */
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
	if (exit_code == EXIT_SUCCESS)
		ft_printf("\033[32m\033[47m\033[1m    • So_Long ended •    \033[0m\n");
	exit(exit_code);
}

bool	mlx_create(t_data *data, int width, int height)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (false);
	data->win = mlx_new_window(data->mlx, width * SX, height * SY, "so_long");
	if (!data->win)
	{
		free(data->mlx);
		return (false);
	}
	return (true);
}

static int	end_loop(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

static bool	verif_ext(char *file, char *ext)
{
	int		len;
	int		pad;

	len = ft_strlen(file);
	pad = ft_strlen(ext);
	if (len < pad)
		return (false);
	while (pad--)
	{
		if (file[len - pad] != ext[ft_strlen(ext) - pad])
			return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_images	images;
	t_map		*map_data;

	map_data = NULL;
	if (argc != 2 || !verif_ext(argv[1], ".ber"))
		return (err_v("Error : Format has to be : %s <map>.ber", argv[0]));
	if (!get_map(argv[1], &map_data))
		return (close_window(&data, EXIT_FAILURE));
	if (!mlx_create(&data, map_data->width, map_data->height))
		return (err("Error : Something went wrong during window creation"));
	if (!init_images(data.mlx, &images))
		return (1);
	display_images(data.mlx, data.win, &images, map_data);
	mlx_hook(data.win, 17, 0, end_loop, &data);
	mlx_key_hook(data.win, handle_keypress, &data);
	mlx_loop(data.mlx);
	free_map(&map_data);
	close_window(&data, EXIT_SUCCESS);
	return (0);
}
