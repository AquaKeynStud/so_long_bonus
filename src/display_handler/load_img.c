/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:43:57 by arocca            #+#    #+#             */
/*   Updated: 2025/03/07 14:46:28 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"
#include "so_long.h"

void	free_images(t_data *data, t_images *img)
{
	mlx_destroy_image(data->mlx, img->wall);
	mlx_destroy_image(data->mlx, img->floor);
	mlx_destroy_image(data->mlx, img->collec);
	mlx_destroy_image(data->mlx, img->player);
	mlx_destroy_image(data->mlx, img->exit);
	data->images = NULL;
}

static bool	load_images(void *mlx, void **imgs, char **paths)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = SX;
	y = SY;
	while (i < 5)
	{
		imgs[i] = mlx_xpm_file_to_image(mlx, paths[i], &x, &y);
		if (!imgs[i])
		{
			err_v("Error: Failed to load asset : %s", paths[i]);
			while (i--)
				mlx_destroy_image(mlx, imgs[i]);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	init_images(void *mlx, t_images *img)
{
	void	*imgs[5];
	char	*paths[5];

	paths[0] = "./assets/wall.xpm";
	paths[1] = "./assets/floor.xpm";
	paths[2] = "./assets/collectible.xpm";
	paths[3] = "./assets/player.xpm";
	paths[4] = "./assets/exit.xpm";
	if (!load_images(mlx, imgs, paths))
		return (false);
	img->wall = imgs[0];
	img->floor = imgs[1];
	img->collec = imgs[2];
	img->player = imgs[3];
	img->exit = imgs[4];
	return (true);
}
