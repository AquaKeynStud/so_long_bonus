/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:43:57 by arocca            #+#    #+#             */
/*   Updated: 2025/03/13 00:15:15 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_data *data, t_images *img)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx, img->wall);
	mlx_destroy_image(data->mlx, img->floor);
	mlx_destroy_image(data->mlx, img->collec);
	mlx_destroy_image(data->mlx, img->exit);
	mlx_destroy_image(data->mlx, img->slime);
	while (i < 4)
	{
		mlx_destroy_image(data->mlx, img->player[i]);
		i++;
	}
	data->images = NULL;
}

static bool	load_images(void *mlx, void **imgs, char **paths, int max)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = SX;
	y = SY;
	while (i < max)
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

bool	load_player(t_data *data, t_images *img)
{
	char	*paths[4];

	paths[0] = "./assets/p_down.xpm";
	paths[1] = "./assets/p_right.xpm";
	paths[2] = "./assets/p_left.xpm";
	paths[3] = "./assets/p_up.xpm";
	if (!load_images(data->mlx, img->player, paths, 4))
		return (false);
	return (true);
}

bool	init_images(t_data *data, t_images *img)
{
	void	*imgs[5];
	char	*paths[5];

	img->direction = 0;
	paths[0] = "./assets/wall.xpm";
	paths[1] = "./assets/floor.xpm";
	paths[2] = "./assets/collectible.xpm";
	paths[3] = "./assets/exit.xpm";
	paths[4] = "./assets/slime1.xpm";
	if (!load_images(data->mlx, imgs, paths, 5))
		return (false);
	img->wall = imgs[0];
	img->floor = imgs[1];
	img->collec = imgs[2];
	img->exit = imgs[3];
	img->slime = imgs[4];
	if (!load_player(data, img))
		return (false);
	return (true);
}
