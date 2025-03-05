/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:15:19 by arocca            #+#    #+#             */
/*   Updated: 2025/03/05 20:41:26 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_data *data, t_images *img)
{
	mlx_destroy_image(data->mlx, img->wall);
	mlx_destroy_image(data->mlx, img->floor);
	mlx_destroy_image(data->mlx, img->collec);
	mlx_destroy_image(data->mlx, img->player);
	mlx_destroy_image(data->mlx, img->exit);
}

static bool	load_images(void *mlx, void *imgs[5], char *paths[5])
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = SX;
	y = SY;
	while (i < 5)
	{
		*((void **)imgs[i]) = mlx_xpm_file_to_image(mlx, paths[i], &x, &y);
		if (!imgs[i])
			return (err_v("Error: Failed to load asset : %s", paths[i]));
		i++;
	}
	return (false);
}

bool	init_images(void *mlx, t_images *img)
{
	void	*imgs[5];
	char	*paths[5];

	imgs[0] = &img->wall;
	imgs[1] = &img->floor;
	imgs[2] = &img->collec;
	imgs[3] = &img->player;
	imgs[4] = &img->exit;
	paths[0] = "./assets/wall.xpm";
	paths[1] = "./assets/floor.xpm";
	paths[2] = "./assets/collectible.xpm";
	paths[3] = "./assets/player.xpm";
	paths[4] = "./assets/exit.xpm";
	return (!load_images(mlx, imgs, paths));
}

void	display_images(void *m, void *w, t_images *img, t_map *map_data)
{
	int		x;
	int		y;
	char	t;

	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			t = find_type(map_data->map[y][x]);
			if (t != -1)
			{
				mlx_put_image_to_window(m, w, img->floor, x * SX, y * SY);
				mlx_put_image_to_window(m, w, get_img(img, t), x * SX, y * SY);
			}
			x++;
		}
		y++;
	}
}
